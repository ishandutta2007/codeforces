#include  <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int cnt[N][N], x, n;

vector < vector <int> > ans;

bool pd(int x) {
	int tot = 0;
	for(int i = 1; i <= n; ++ i) tot += (!!cnt[x][i]);
	return (tot == n);
}

int get() {
	int tot = 0;
	for(int i = 1; i <= n; ++ i) {
		if(pd(i)) ++ tot;
	}
	return tot;
}

int nxt(int x) {
	++ x;
	if(x == n + 1) x -= n;
	return x;
}

vector <int> res;

void Choose(int x, int who) {
	res[x - 1] = who;
	-- cnt[x][who];
	++ cnt[nxt(x)][who]; 
}

void solve1() {
	int tot = get();
	while(tot < n) {
		vector <int> all;
		for(int i = 1; i <= n; ++ i) {
			if(pd(i)) continue;
			all.push_back(i);
		}
		res.resize(n);
		for(int j = 0; j < (int) all.size(); ++ j) {
			int now = (all[(j + 1) % (int) all.size()]);
			int cur = all[j], who = 0;
			for(int i = 1; i <= n; ++ i) if(cnt[cur][i] >= 2) who = i;
			while(cur != now) {
				Choose(cur, who);
				cur = nxt(cur);
			}
		}
		ans.push_back(res);
		tot = get();
	}
}

void solve(int k) {
	vector <int> All;
	for(int i = 1; i <= n; ++ i) {
		int now = (i + k);
		if(now > n) now -= n;
		All.push_back(now);
	}
	ans.push_back(All);
}

void solve2() {
	for(int d = 1; d <= n - 1; ++ d) {
		for(int j = d; j >= 1; -- j) solve(j);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) scanf("%d", &x), ++ cnt[i][x];
	}
	solve1();
	solve2();
	cout << ans.size() << endl;
	for(auto V : ans) {
		for(auto x : V) printf("%d ", x);
		puts("");
	}
}