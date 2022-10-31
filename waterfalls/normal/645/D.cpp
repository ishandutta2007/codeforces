#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n,m;
vector<pair<int,int> > adj[100013];
bool vis[100013];
vector<int> topo;
int len[100013];
int high[100013];

void dfs(int x) {
	vis[x] = 1;
	for (auto i: adj[x]) if (!vis[i.A]) dfs(i.A);
	topo.push_back(x);
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(MP(b,i));
	}
	for (int i=1;i<=n;i++) if (!vis[i]) dfs(i);
	reverse(topo.begin(),topo.end());
	for (int i: topo) {
		len[i] = max(len[i],1);
		for (auto p: adj[i]) {
			int j = p.A;
			if (len[i]+1>len[j]) {
				len[j] = len[i]+1;
				high[j] = max(high[i],p.B);
			}
		}
	}
	if (len[topo.back()]==n) printf("%d\n",high[topo.back()]);
	else printf("-1\n");

    return 0;
}