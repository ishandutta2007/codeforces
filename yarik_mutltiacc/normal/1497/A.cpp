// Problem: A. Meximization
// Contest: Codeforces - Codeforces Round #708 (Div. 2)
// URL: https://codeforces.com/contest/1497/problem/A
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
		vector<int> cnt(101), res;
		for(int t, i = 0; i < n; i++) cin >> t, cnt[t]++;
		for(int i = 0; i < cnt.size(); i++)
			if(cnt[i]) res.push_back(i), cnt[i]--;
		for(int i = 0; i < cnt.size(); i++)
			while(cnt[i]) res.push_back(i), cnt[i]--;
		for(auto &i : res) cout << i << " "; cout << endl;
	});
	
}