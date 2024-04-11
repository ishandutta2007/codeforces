#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(3e5)+10;
int T,n,m,head[maxn],tot,nxt[maxn*2],to[maxn*2];
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
bool vis[maxn];
void dfs(int u) {
	if (vis[u]) return; vis[u]=1;
	for (int i=head[u];i;i=nxt[i]) dfs(to[i]);
}
int ans[maxn],cnt;
queue<int> q;
int main() {
	//freopen("1.txt","r",stdin);
	int x,y;
	read(T);
	while (T--) {
		read(n),read(m); tot=0;
		for (int i=1;i<=n;i++) head[i]=vis[i]=0,ans[i]=-1;
		while (m--) {
			read(x),read(y);
			add(x,y),add(y,x);
		}
		dfs(1);
		int flag=1;
		for (int i=1;i<=n;i++) if (!vis[i]) { flag=0; break; }
		if (!flag) { puts("NO"); continue; }
		q.push(1);
		while (!q.empty()) {
			int u=q.front(); q.pop();
			if (ans[u]!=-1) continue;
			ans[u]=1;
			for (int i=head[u],v;i;i=nxt[i]) {
				v=to[i];
				if (ans[v]==0) continue;
				ans[v]=0;
				for (int j=head[v],k;j;j=nxt[j]) {
					k=to[j];
					if (ans[k]==-1) q.push(k);
				}
			}
		}
		cnt=0;
		for (int i=1;i<=n;i++) if (ans[i]==1) cnt++;
		puts("YES");
		printf("%d\n",cnt);
		for (int i=1;i<=n;i++) if (ans[i]==1) printf("%d ",i); puts("");
	}
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