#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, nxt[402][26];
string s, t;
int dp[401][401];

bool solve2(string t1, string t2) {
	dp[0][0]=-1;
	for(int i=0; i<=t1.size(); ++i) {
		for(int j=0; j<=t2.size(); ++j) {
			if(!i&&!j)
				continue;
			dp[i][j]=n;
			if(i)
				dp[i][j]=min(dp[i][j], nxt[dp[i-1][j]+1][t1[i-1]-'a']);
			if(j)
				dp[i][j]=min(dp[i][j], nxt[dp[i][j-1]+1][t2[j-1]-'a']);
		}
	}
	return dp[t1.size()][t2.size()]<n;
}

void solve() {
	cin >> s >> t;
	n=s.size();
	m=t.size();
	for(int i=0; i<26; ++i)
		nxt[n][i]=nxt[n+1][i]=n;
	for(int i=n-1; ~i; --i) {
		memcpy(nxt[i], nxt[i+1], sizeof(nxt[0]));
		nxt[i][s[i]-'a']=i;
	}
	//cout << nxt[0]['x'-'a'] << endl;
	for(int i=0; i<m; ++i)
		if(solve2(t.substr(0, i), t.substr(i))) {
			cout << "YES\n";
			return;
		}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}