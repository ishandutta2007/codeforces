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
		ll n;
		cin >> n;
		auto disum = [](ll x) {
			string s = to_string(x);
			ll ans = 0;
			for(auto i : s) ans += i-'0';
			return ans;
		};
		while(__gcd(n, disum(n))==1)n++;
		cout << n << '\n';
	});
	
}