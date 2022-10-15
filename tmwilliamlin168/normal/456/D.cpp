#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5, as=26;
int n, k;
int sz=1, nxt[mxN+1][as];
bool dp[mxN+1][2];

inline void ins(string &s) {
	for(int c=0, i=0; i<s.size(); c=nxt[c][s[i]-'a'], ++i)
		if(!nxt[c][s[i]-'a'])
			nxt[c][s[i]-'a']=sz++;
}

void cdp(int i) {
	bool l=1;
	for(int j=0; j<as; ++j) {
		if(!nxt[i][j])
			continue;
		cdp(nxt[i][j]);
		dp[i][0]|=!dp[nxt[i][j]][0], dp[i][1]|=!dp[nxt[i][j]][1];
		l=0;
	}
	dp[i][1]|=l;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	while(n--) {
		string s;
		cin >> s;
		ins(s);
	}
	cdp(0);
	cout << (dp[0][0]&&(dp[0][1]||k%2)?"First":"Second");
}