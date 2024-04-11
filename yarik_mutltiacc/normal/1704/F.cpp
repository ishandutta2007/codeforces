// Problem: F. -
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/F
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
	vector<int> val(101010);
	for(int i = 2; i < 200; i++) {
		vector<int> vals(i+1);
		for(int j = 0; i-j-2 >= 0; j++)
			vals[val[j] ^ val[i-j-2]] = 1;
		while(vals[val[i]])
			val[i]++;
		// cout << i << " " << val[i] << endl;
	}
	multitest([&](){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int bal = 0, rb = 0, cnt = 0;
		vector<int> line;
		for(int i = 0; i < n; i++) {
			bal += s[i] == 'R' ? 1 : -1;
			if(i == 0 || s[i] != s[i-1]) {
				cnt++;
			} else {
				if(cnt > 1) line.push_back(cnt);
				cnt = 1;
			}
		}
		if(cnt > 1) line.push_back(cnt);
		if(bal == 0) {
			int x = 0;
			for(auto i : line) {
				if(i > 100) {
					i -= 100;
					i %= 34;
					i += 100;
				}
				x ^= val[i];
			}
			bal = x ? 1 : -1;
		}
		cout << (bal > 0 ? "Alice" : "Bob") << '\n';
	});
	
}