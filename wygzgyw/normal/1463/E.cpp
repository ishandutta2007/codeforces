#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(3e5)+10;
int n,m,fa[maxn],ans[maxn],tot;
queue<int> q;
vector<int> g[maxn];
int nxt[maxn],deg[maxn],bel[maxn],vis[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	int x,y;
	read(n),read(m);
	for (int i=1;i<=n;i++) read(fa[i]);
	while (m--) {
		read(x),read(y);
		nxt[x]=y,vis[y]=1;
	}
	int u=0;
	for (int i=1;i<=n;i++) if (!vis[i]) {
		for (int j=i;j;j=nxt[j]) {
			bel[j]=i;
			if (fa[j]&&bel[fa[j]]!=i) g[fa[j]].push_back(i),deg[i]++;
		}
		if (!deg[i]) u=i;
	}
	if (u) q.push(u);
	while (!q.empty()) {
		u=q.front(); q.pop();
		for (int v=u,v2;v;v=nxt[v]) {
			ans[++tot]=v;
			for (int i=0;i<g[v].size();i++) {
				v2=g[v][i];
				deg[v2]--;
				if (!deg[v2]) q.push(v2);
			}
		}
	}
	if (tot==n) {
		for (int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
	} else printf("0\n");
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/