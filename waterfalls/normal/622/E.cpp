#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[500013];
int has[500013];

int dfs(int x, int p=1, int d=1) {
	int res = d;
	for (int i: adj[x]) if (i!=p) res = max(res,dfs(i,x,d+1));
	if (res==d) has[d]+=1;
	return res;
}

int solve(int x) {
	int high = dfs(x,1,1);
	int res = 0;
	for (int i=1;i<=high;i++) {
		res = max(i,res+has[i]);
		has[i] = 0;
	}
	return res;
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	for (int i: adj[1]) ans = max(ans,solve(i));
	printf("%d\n",ans);

	return 0;
}