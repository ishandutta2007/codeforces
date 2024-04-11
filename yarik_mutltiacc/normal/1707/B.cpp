// Problem: B.  
// Contest: Codeforces - Codeforces Round #808 (Div. 1)
// URL: https://codeforces.com/contest/1707/problem/B
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
		int n;
		cin >> n;
		//00x->0x
		map<int, int> cnt;
		for(int t, i = 0; i < n; i++) {
			cin >> t;
			cnt[t]++;
		}
		vector<pair<int, int>> a(all(cnt));
		//after 2 iter sqrt distinct
		//after sqrt iter 1 nonzero?
		while(a.size() > 1 || a[0].second > 1) {
			map<int, int> cnt;
			for(int i = 1; i < a.size(); i++)
				cnt[a[i].first - a[i-1].first]++;
			for(int i = 0; i < a.size(); i++) if(a[i].second > 1)
				cnt[0] += a[i].second - 1;
			a = vector<pair<int, int>>(all(cnt));
		}
		cout << a[0].first << '\n';
	});
	
}