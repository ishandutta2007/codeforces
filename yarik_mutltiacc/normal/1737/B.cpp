// Problem: B.     
// Contest: Codeforces - Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/B
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
		ll l, r;
		cin >> l >> r;
		auto get = [&](ll N) {
			ll ans = 0;
			for(int i = 0; i < 3; i++) {
				ll n = 0;
				for(ll z = 1ll<<31; z>>=1;) {
					ll tn = n+z;
					tn = tn*(tn+i);
					n += z*(tn <= N);
				}
				ans += n;
			}
			return ans;
		};
		cout << get(r) - get(l-1) << '\n';
	});
	
}