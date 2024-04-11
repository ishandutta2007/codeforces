#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int nxt[100001][26];

void solve() {
	string s, t;
	cin >> s >> t;
	int c1[26]={}, c2[26]={};
	for(char c : s)
		++c1[c-'a'];
	for(char c : t)
		++c2[c-'a'];
	for(int i=0; i<26; ++i)
		if(c2[i]&&!c1[i]) {
			cout << "-1\n";
			return;
		}
	for(int i=0; i<26; ++i)
		nxt[s.size()][i]=s.size();
	for(int i=s.size()-1; ~i; --i) {
		memcpy(nxt[i], nxt[i+1], 4*26);
		nxt[i][s[i]-'a']=i;
	}
	for(int i=s.size()-1; ~i; --i) {
		for(int j=0; j<26; ++j) {
			if(c1[j]&&nxt[i][j]==s.size()) {
				nxt[i][j]=nxt[0][j];
			}
		}
	}
	int ans=1;
	int i=-1;
	for(char c : t) {
		if(nxt[(i+1)%s.size()][c-'a']<=i)
			++ans;
		i=nxt[(i+1)%s.size()][c-'a'];
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}