#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, A=26;
string s, t;
int n, m;
vector<vector<int>> dp;

struct autoac {
	int sl[mxN+1], sz=1, c[mxN+1][A], d[mxN+1][A], w[mxN+1];
	void add(string s, int x) {
		int u=0;
		for(char a : s) {
			if(!c[u][a-'a'])
				c[u][a-'a']=sz++;
			u=c[u][a-'a'];
		}
		w[u]+=x;
	}
	void ac() {
		for(queue<int> q({0}); q.size(); q.pop()) {
			int u=q.front();
			w[u]+=w[sl[u]];
			for(int a=0; a<A; ++a) {
				int v=c[u][a], s=sl[u];
				if(v) {
					sl[v]=d[s][a];
					q.push(v);
				}
				d[u][a]=v?v:d[s][a];
			}
		}
	}
} ac;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;
	n=s.size(), m=t.size();
	ac.add(t, 0);
	ac.ac();
	dp=vector<vector<int>>(n+1, vector<int>(m+1, -1e9));
	dp[0][0]=0;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<=m; ++j) {
			for(int k=0; k<26; ++k) {
				if(s[i]=='?'||s[i]=='a'+k) {
					int l=ac.d[j][k];
					dp[i+1][l]=max(dp[i+1][l], dp[i][j]+(l==m));
				}
			}
		}
	}
	cout << *max_element(dp[n].begin(), dp[n].end());
}