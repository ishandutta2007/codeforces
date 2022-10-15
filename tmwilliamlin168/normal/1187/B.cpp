#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, a[26][mxN+1], c[26];
string s, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s >> m;
	for(int i=0; i<n; ++i) {
		++c[s[i]-'a'];
		a[s[i]-'a'][c[s[i]-'a']]=i+1;
	}
	while(m--) {
		cin >> t;
		memset(c, 0, sizeof(c));
		for(char d : t)
			++c[d-'a'];
		int ans=0;
		for(int i=0; i<26; ++i)
			ans=max(ans, a[i][c[i]]);
		cout << ans << "\n";
	}
}