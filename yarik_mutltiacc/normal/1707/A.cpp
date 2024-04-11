// Problem: A.    IQ
// Contest: Codeforces - Codeforces Round #808 (Div. 1)
// URL: https://codeforces.com/contest/1707/problem/A
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
		int n, k;
		cin >> n >> k;
		vector<ll> a(n);
		for(auto &i : a) cin >> i;
		int cur_iq = 0;
		reverse(all(a));
		string ans;
		for(auto i : a) {
			if(i <= cur_iq) ans += '1';
			else if(cur_iq < k) cur_iq++, ans += '1';
			else ans += '0';
		}
		reverse(all(ans));
		cout << ans << '\n';
	});
	
}