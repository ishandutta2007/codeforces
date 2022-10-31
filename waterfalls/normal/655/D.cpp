#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100013], b[100013];
vector<int> adj[100013];
bool vis[100013];
vector<int> topo;
int len[100013];

void dfs(int x) {
	vis[x] = 1;
	for (int i: adj[x]) if (!vis[i]) dfs(i);
	topo.push_back(x);
}

bool check(int k) {
	for (int i=1;i<=n;i++) adj[i].clear();
	for (int i=1;i<=k;i++) adj[a[i]].push_back(b[i]);
	memset(vis,0,sizeof vis);
	topo.clear();
	for (int i=1;i<=n;i++) if (!vis[i]) dfs(i);
	reverse(topo.begin(),topo.end());
	memset(len,0,sizeof len);
	for (int i: topo) {
		len[i] = max(len[i],1);
		for (int j: adj[i]) {
			if (len[i]+1>len[j]) len[j] = len[i]+1;
		}
	}
	if (len[topo.back()]==n) return true;
	return false;
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&a[i],&b[i]);
	int low = 0;
	int high = m+1;
	while (high-low>1) {
		if (check((low+high+1)/2)) high = (low+high+1)/2;
		else low = (low+high+1)/2;
	}
	if (high==m+1) high = -1;
	printf("%d\n",high);

    return 0;
}