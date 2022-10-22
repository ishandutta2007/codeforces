// Problem: E. Two Houses
// Contest: Codeforces - CodeCraft-21 and Codeforces Round #711 (Div. 2)
// URL: https://codeforces.com/contest/1498/problem/E
// Memory Limit: 256 MB
// Time Limit: 3500 ms
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
const int local = 0;
int ask(int x, int y) {
	cout << "? " << x << " " << y << endl;
	string t;
	if(local) {
		
	}
	cin >> t;
	return t[0] == 'Y';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n;
	cin >> n;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<array<int, 3>> q;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			q.push_back({abs(a[i]-a[j]), i, j});
		}
	}
	sort(all(q), greater<>());
	for(auto &[d, x, y] : q) {
		if(a[x] < a[y]) swap(x, y);
		if(ask(x, y)) {
			cout << "! " << x << " " << y << endl;
			exit(0);
		}
	}
	cout << "! 0 0\n";
}