#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int UB = 100000;

int N;
long long R;
int ls[200200], ts[200200];

long long len[200200], req[200200];

long long mag[200200], val[200200], t;
long long ans[UB + 10];
int c;
long long all_num;

void solve(){
	for(int i = 0; i < N; ++i){
		if(ls[i] > ts[i]){
			cout << -1 << "\n";
			exit(0);
		}
		req[i] = 2 * ls[i] - ts[i];
		len[i] = ls[i];
		if(req[i] < 0) req[i] = 0;
	}
		
	all_num = 0;
	c = 0;
	bool flg = true;
	for(int i = 0; i < N; ++i){
		int loop = (req[i] - mag[i]) / R;
		if(loop < 0) loop = 0;
		if(c + loop > UB){
			flg = false;
		}
		if(flg){
			while(req[i] - mag[i] >= R){
				ans[c++] = t;
				all_num++;
				mag[i] += R;
				val[i] += R;
				t += R;
			//	cerr << t << endl;
			}
		}else{
			all_num += loop;
			t += loop * R;
			val[i] += loop * R;
			mag[i] += loop * R;
		}
		//cerr << t << endl;
		if(len[i] == val[i]) continue;
		long long normal_dis = len[i] - val[i] - max(0ll, (req[i] - mag[i]));
		//cerr << "nor" << normal_dis << endl;
		t += normal_dis * 2;
		val[i] += normal_dis;
		if(req[i] - mag[i] > 0){
			long long tmp = R;
			for(int j = i; j < N; ++j){
				long long rem = len[j] - val[j];
				long long cur = min(rem, tmp);
				val[j] += cur;
				mag[j] += cur;
				tmp -= cur;
				if(tmp == 0) break;
			}
			if(flg) ans[c++] = t;
			all_num++;
			t += R;
			if(c > UB) flg = false;
		}
	}
}

void output(){
	if(all_num <= UB){
//		printf("%d\n", c);
		cout << c << "\n";
		for(int i = 0; i < c; ++i){
			cout << ans[i] << (i == c - 1 ? '\n' : ' ');
		}
	}else{
		cout << all_num;
	}
}

void input(){
	cin >> N >> R;
	for(int i = 0; i < N; ++i){
//		scanf("%d", ls + i);
		cin >> ls[i];
	}
	for(int i = 0; i < N; ++i){
//		scanf("%d", ts + i);
		cin >> ts[i];
	}
}

int main(){
	ios::sync_with_stdio(false);
	input();
	solve();
	output();
	return 0;
}