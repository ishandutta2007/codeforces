#include <bits/stdc++.h>

using namespace std;

int n,m,ans;
int has[100013];
vector<int> adj[100013];

void dfs(int x, int p=0, int s=0) {
	if (has[x]) s+=1;
	else s = 0;
	if (s>m) return;
	int cnt = 0;
	for (int i: adj[x]) if (i!=p) cnt+=1, dfs(i,x,s);
	if (cnt==0) ans+=1;
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&has[i]);
	for (int i=1;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans = 0;
	dfs(1);
	printf("%d\n",ans);

	return 0;
}