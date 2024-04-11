// Problem: C. 
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/C
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
		ll n, m;
		cin >> n >> m;
		vector<ll> _a(m), a;
		for(auto &i : _a) cin >> i;
		sort(all(_a));
		for(int i = 0; i < m; i++) {
			ll x = (-_a[i] + _a[(i+1)%m] + n + n - 1)%n;
			a.push_back(x);
		}
		sort(all(a), greater<>());
		ll cur = 0, ans= 0;
		for(int i = 0; i < m; i++) {
			ll t = a[i] - 2*cur - 1;
			if(t == 0) t = 1, cur--;
			if(t < 0) break;
			cur += 2;
			ans += t;
		}
		cout << n - ans << '\n';
	});
}