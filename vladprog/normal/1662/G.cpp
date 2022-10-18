// Problem: G. Gastronomic Event
// Contest: Codeforces - SWERC 2021-2022 - Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1662/problem/G
// Memory Limit: 512 MB
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
const int N = 1e6 + 66;
int n, p[N], sz[N];
vector<int> g[N];
ll sum[N];
ll sizes(int v) {
	sz[v] = 1;
	ll cur = 0;
	for(auto i : g[v]) {
		cur += sizes(i);
		sz[v] += sz[i];
	}
	return cur+sz[v];
}
void sums(int v) {
	for(auto &i : g[v]) {
		sum[i] = sum[v] + n - 2*sz[i];
		sums(i);
	}
}
int centr(int v) {
	for(auto &i : g[v])
		if(2*sz[i] >= n)
			return centr(i);
	return v;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n;
	for(int t, i = 1; i < n; i++) {
		cin >> t;
		p[i] = t;
		g[t-1].push_back(i);
	}
	sum[0] = sizes(0);
	sums(0);
	int C = centr(0);
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ll mx = n-sz[i];
		for(auto &j : g[i])
			mx = max(mx, (ll)sz[j]);
		ans = max(ans, sum[i] + (n-1-mx)*mx);
	}
	map<int, int> cnt;
	if(C) cnt[n-sz[C]]++;
	for(auto &i : g[C]) cnt[sz[i]]++;
	bitset<N> bt;
	bt[0] = 1;
	for(auto [v, c] : cnt) {
		int r = 1;
		while(c) {
			int t = min(r, c);
			bt |= bt<<(t*v);
			r *= 2;
			c -= t;
		}
	}
	for(int i = 0; i < n; i++) if(bt[i])
		ans = max(ans, sum[C] + (n-1-i)*1ll*i);
	cout << ans << '\n';
}