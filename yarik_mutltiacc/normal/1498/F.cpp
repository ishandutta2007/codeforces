// Problem: F. Christmas Game
// Contest: Codeforces - CodeCraft-21 and Codeforces Round #711 (Div. 2)
// URL: https://codeforces.com/contest/1498/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int maxn = 1<<17;
int k;
struct sol {
	array<int, 41> f;
	sol() {
		fill(all(f), 0);
	}
	void shift() {
		int z = f[2*k-1];
		for(int i =2*k-1; i>0; i--)
			f[i] = f[i-1];
		f[0] = z;
	}
	void upd(int x) {
		f[0] ^= x;
	}
	friend sol operator+(sol a, const sol &b) {
		for(int i = 0; i < 2*k; i++)
			a.f[i] ^= b.f[i];
		return a;
	}
	bool eval() {
		int res = 0;
		for(int i = k; i < 2*k; i++)
			res ^= f[i];
		return !!res;
	}
};
int n;
vector<int> g[maxn];
int a[maxn];
sol dp[maxn];
void calc(int v, int p) {
	dp[v].upd(a[v]);
	for(auto i : g[v]) if(i != p) {
		calc(i, v);
		auto t = dp[i];
		t.shift();
		dp[v] = dp[v]+t;
	}
}
int ans[maxn];
void solve(int v, int p, sol &cur) {
	ans[v] = cur.eval();
	for(auto i : g[v]) if(i != p) {
		auto chi = cur;
		auto t = dp[i];
		t.shift();
		chi = chi+t;
		chi.shift();
		chi = dp[i] + chi;
		solve(i, v, chi);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> k;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	for(int i = 1; i <= n; i++) cin >> a[i];
	calc(1, -1);
	solve(1, -1, dp[1]);
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
}