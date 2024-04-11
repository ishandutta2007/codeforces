#include<cstdio>
#include<utility>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

int R,C;
int N;
vector<int> js[3030];
int K;

int prv[3030],nxt[3030];

int cnt[3030];
int ri[3030];
int num[3030];//first > K

long long sum_ri;
long long sum_le;

set<int> se;

void init(){
	sum_le = 0;
	for(int i = 0; i <= C; ++i) sum_le += i;
	for(int i = 0; i <= C; ++i){
		cnt[i] = 0;
		ri[i] = C;
		num[i] = 100;
		prv[i] = -1;
		nxt[i] = C;
	}
	nxt[C] = C + 1;
	cnt[C] = 100;
	sum_ri = (long long)C * (C + 1);
	set<int> tmp;
	swap(se,tmp);
	se.insert(-1);
	se.insert(C);
}

void ins(int j){
	if(cnt[j] == 0){
		int n = *se.lower_bound(j);
		int p = prv[n];
		nxt[p] = j;
		nxt[j] = n;
		prv[n] = j;
		prv[j] = p;
		cnt[j]++;
		sum_ri -= (long long)(j - p) * ri[n];
		se.insert(j);
	}else{
		sum_ri -= (long long)(j - prv[j]) * ri[j];
		cnt[j]++;
	}
	int new_ri = -1;
	int new_num = 0;
	for(int t = j; t <= C; t = nxt[t]){
		new_num += cnt[t];
		if(new_num >= K){
			new_ri = t;
			break;
		}
	}
	ri[j] = new_ri;
	num[j] = new_num;
	sum_ri += (long long)ri[j] * (j - prv[j]);
	for(int le = prv[j]; le >= 0 && ri[le] >= j; le = prv[le]){
		num[le]++;
		int cur_ri = ri[le];
		if(num[le] - cnt[cur_ri] >= K){
			int nxt_ri = prv[cur_ri];
			sum_ri -= (long long)(cur_ri - nxt_ri) * (le - prv[le]);
			num[le] -= cnt[cur_ri];
			ri[le] = nxt_ri;
		}
	}
}

long long calc_fixed_i(int I){
	long long ans = 0;
	init();
	for(int i = I; i < R; ++i){
		for(int j: js[i]){
			ins(j);
		}
		ans += (sum_ri - sum_le);
	}
	return ans;
}

long long solve(){
	long long sum = 0;
	for(int i = 0; i < R; ++i){
		long long tmp = calc_fixed_i(i);
		sum += tmp;
	}
	long long all = (long long)R * (R + 1) * C * (C + 1) / 4;
	return all - sum;
}

void input(){
	scanf("%d%d%d%d", &R,&C,&N,&K);
	for(int i = 0; i < N; ++i){
		int i_, j_;
		scanf("%d%d", &i_, &j_);
		i_--;
		j_--;
		js[i_].push_back(j_);
	}
}

int main(){
	input();
	long long ans = solve();
	printf("%I64d\n", ans);
	return 0;
}