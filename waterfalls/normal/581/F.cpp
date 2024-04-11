#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[5013];
int s[5013];
int can[5013][5013];

void solve(int x, int p=0) {
	s[x] = (adj[x].size()==1);
	for (int i=0;i<=n;i++) can[x][i] = 1e9;
	can[x][0] = 0;
	for (int i: adj[x]) if (i!=p) {
		solve(i,x);
		for (int j=s[x];j>=0;j--) for (int u=0;u<=s[i];u++) {
			can[x][j+u] = min(can[x][j+u],can[i][u]+can[x][j]);
		}
		s[x]+=s[i];
	}
	for (int i=0;i<=s[x];i++) can[x][s[x]-i] = min(can[x][s[x]-i],1+can[x][i]);
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int root = 1;
	while (adj[root].size()==1) root+=1;
	solve(root);
	printf("%d\n",n==2 ? 1 : can[root][s[root]/2]);

	return 0;
}