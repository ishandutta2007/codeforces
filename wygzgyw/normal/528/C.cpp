#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e6)+10;
int n,m,tot,deg[maxn],ans[maxn];
int nxt[maxn],to[maxn],head[maxn];
bool vis[maxn];
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
void dfs(int u) {
	for (int i=head[u],v;i;i=head[u]) {
		head[u]=nxt[i];
		v=to[i];
		if (vis[i]) continue;
		vis[i]=vis[i^1]=1;
		dfs(v);
	}
	ans[++tot]=u;
}
int main() {
	//freopen("1.txt","r",stdin);
	tot=1;
	read(n); read(m);
	int x,y;
	for (int i=1;i<=m;i++) {
		read(x); read(y);
		add(x,y); add(y,x);
		deg[x]++; deg[y]++;
	}
	x=0;
	for (int i=1;i<=n;i++)
		if (deg[i]&1) {
			if (!x) x=i;
			else add(x,i),add(i,x),m++,x=0;
		}
	if (m&1) add(1,1),add(1,1),m++;
	printf("%d\n",m);
	tot=0;
	dfs(1);
	for (int i=1;i<tot;i++) {
		if (i&1) printf("%d %d\n",ans[i],ans[i+1]);
		else printf("%d %d\n",ans[i+1],ans[i]);
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