// Problem: C.   
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/C
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		vector<array<int, 2>> b;
		for(int i = 1; i < n; i++)
			b.push_back({a[i]-a[i-1], i});
		b.push_back({1<<30, 0});
		sort(all(b));
		reverse(all(b));
		for(auto &i : b) cout << 1+i[1] << " "; cout << '\n';
	});
	
}