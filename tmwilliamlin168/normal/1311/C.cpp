#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, d[200000];
ll c[26];
string s;

void solve() {
	cin >> n >> m >> s;
	memset(d, 0, 4*n);
	++d[n-1];
	for(int i=0; i<m; ++i) {
		int p;
		cin >> p;
		++d[p-1];
	}
	for(int i=n-1; i; --i)
		d[i-1]+=d[i];
	memset(c, 0, 8*26);
	for(int i=0; i<n; ++i) {
		c[s[i]-'a']+=d[i];
	}
	for(int i=0; i<26; ++i)
		cout << c[i] << " \n"[i==25];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}