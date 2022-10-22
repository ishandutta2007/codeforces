// Problem: B. Box Fitting
// Contest: Codeforces - CodeCraft-21 and Codeforces Round #711 (Div. 2)
// URL: https://codeforces.com/contest/1498/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		ll n, w;
		cin >> n >> w;
		vector<ll> cnt(33);
		int sum = 0;
		for(int t, i = 0; i < n; i++) {
			cin >> t;
			cnt[__lg(t)]++;
			sum++;
		}
		ll ans = 0;
		while(sum) {
			ans++;
			ll cw = w;
			for(ll i = cnt.size(); i--;) {
				ll t = min(cw>>i, (ll)cnt[i]);
				cw -= t<<i;
				sum -= t;
				cnt[i] -= t;
			}
		}
		cout << ans << '\n';
	});
	
}