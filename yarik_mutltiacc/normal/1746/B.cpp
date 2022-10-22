// Problem: B. 
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/B
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
		vector<int> a[2];
		for(int t, i = 0; i < n; i++) {
			cin >> t;
			a[t^1].push_back(i);
		}
		int ops = 0;
		while(ops < min(a[0].size(), a[1].size())
			&& a[0][ops] < a[1][(int)a[1].size() - 1 - ops])
			ops++;
		cout << ops << '\n';
	});
	
}