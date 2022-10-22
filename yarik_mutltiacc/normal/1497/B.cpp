// Problem: B. M-arrays
// Contest: Codeforces - Codeforces Round #708 (Div. 2)
// URL: https://codeforces.com/contest/1497/problem/B
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
		map<int, array<int, 2>> cnt;
		int n, m;
		cin >> n >> m;
		for(int t, i = 0; i < n; i++) {
			cin >> t;
			t %= m;
			int c = min(t, m-t);
			cnt[c][t == c]++;
		}
		int ans = 0;
		for(auto F : cnt) {
			if(F.first == 0 || F.first*2 == m) {ans++;continue;}
			auto i = F.second;
			if(i[0] > i[1]) swap(i[0], i[1]);
			if(i[1] <= i[0]+1) ans++;
			else ans += 1+max(i[1] - i[0] - 1, 0);
		}
		cout << ans << '\n';
	});
	
}