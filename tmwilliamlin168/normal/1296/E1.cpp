#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, c[200];
string s;
bool adj[200][200];

void dfs(int u, int cu) {
	if(~c[u]) {
		if(c[u]^cu) {
			cout << "NO";
			exit(0);
		}
		return;
	}
	c[u]=cu;
	for(int v=0; v<n; ++v)
		if(adj[u][v])
			dfs(v, cu^1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			if(s[i]>s[j]) {
				adj[i][j]=adj[j][i]=1;
			}
		}
	}
	memset(c, -1, 4*n);
	for(int i=0; i<n; ++i)
		if(c[i]<0)
			dfs(i, 0);
	cout << "YES\n";
	for(int i=0; i<n; ++i)
		cout << c[i];
}