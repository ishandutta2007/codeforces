#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> P;

int N;
int rs[110];

int to_dec[110];

vector<vector<int> > ans;

P ps[110];

void print_vec(vector<int> v){
	char ch[110];
	for(int i = 0; i < N; ++i) ch[i] = '0';
	ch[N] = '\0';
	for(int i = 0; i < v.size(); ++i){
		ch[v[i]] = '1';
	}
	printf("%s\n", ch);
}

bool gen(){
	ans.clear();
	int all = 0;
	for(int i = 0; i < N; ++i){
		all += to_dec[i];
		ps[i] = P(to_dec[i], i);
	}
	sort(ps, ps + N);
	reverse(ps, ps + N);
	if(all % 2 == 1){
		if(N < 5) return false;
		vector<int> tmp;
		for(int i = 0; i < 5; ++i){
			ps[i].first--;
			tmp.push_back(ps[i].second);
		}
		ans.push_back(tmp);
	}
	
	sort(ps, ps + N);
	reverse(ps, ps + N);
	
	while(true){
		if(ps[0].first == 0) return true;
		if(ps[1].first == 0) return false;
		vector<int> vec;
		vec.push_back(ps[0].second);
		vec.push_back(ps[1].second);
		ans.push_back(vec);
		ps[0].first--;
		ps[1].first--;
		sort(ps, ps + N);
		reverse(ps, ps + N);
	}
}

void solve(){
	int mi = 110;
	for(int i = 0; i < N; ++i) mi = min(mi, rs[i]);
	for(int t = mi; t > 0; --t){
		for(int i = 0; i < N; ++i) to_dec[i] = rs[i] - t;
		bool flg = gen();
		if(flg){
			printf("%d\n", t);
			printf("%d\n", ans.size());
			for(int i = 0; i < ans.size(); ++i){
				print_vec(ans[i]);
			}
			return;
		}
	}
	printf("0\n");
	printf("%d\n", (N - 1) * 100);
	for(int i = 0; i + 1 < N; ++i){
		vector<int> v;
		v.push_back(i);
		v.push_back(i + 1);
		for(int j = 0; j < 100; ++j){
			print_vec(v);
		}
	}
}

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) scanf("%d", rs + i);
}

int main(){
	input();
	solve();
	return 0;
}

	
	/*
	int ng = (all + 1) / 2;
	
	for(int i = 0; i < N; ++i){
		if(to_dec[i] >= ng){
			return false;
		}
	}
	if(all % 2 == 1){
		if(N < 5) return false;
*/