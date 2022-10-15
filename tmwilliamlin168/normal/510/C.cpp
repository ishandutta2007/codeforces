#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int n;
string s[100], ans;
vector<int> adj[26];
bool vis[26], act[26];
 
void fk() {
	cout << "Impossible";
	exit(0);
}
 
void dfs(int u) {
	vis[u]=1;
	act[u]=1;
	for(int v : adj[u]) {
		if(act[v])
			fk();
		if(!vis[v])
			dfs(v);
	}
	act[u]=0;
	ans+=u+'a';
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> s[i];
		if(i) {
			int j=0;
			while(j<s[i].size()&&j<s[i-1].size()&&s[i][j]==s[i-1][j])
				++j;
			if(j==s[i].size())
				fk();
			if(j<s[i-1].size())
				adj[s[i][j]-'a'].push_back(s[i-1][j]-'a');
		}
	}
	for(int i=0; i<26; ++i)
		if(!vis[i])
			dfs(i);
	cout << ans;
}