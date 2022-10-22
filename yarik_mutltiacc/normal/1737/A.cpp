// Problem: A.   
// Contest: Codeforces - Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/A
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
		string s;
		cin >> n >> k >> s;
		int cnt[26];
		memset(cnt, 0, sizeof cnt);
		for(auto i : s) cnt[i - 'a']++;
		string ans(k, 'a');
		vector<int> lft(k, n/k);
		for(int i = 0; i < 26; i++) {
			for(int j = 0; j < ans.size() && cnt[i]; j++) {
				if(lft[j] && ans[j]-'a' == i)
					ans[j]++, lft[j]--, cnt[i]--;
			}
		}
		cout << ans << '\n';
	});
	
}