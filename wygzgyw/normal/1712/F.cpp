// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
const int maxn=(1e6)+10;
int n;
int dep[maxn];
int out[maxn];
int deg[maxn];
int head[maxn],nxt[maxn*2],to[maxn*2],tot;
void add(int x,int y) { tot++; nxt[tot]=head[x]; head[x]=tot; to[tot]=y; }
int m[maxn];
int MN(int x,int y) { if (dep[x]<dep[y]) return x; return y; }
int mndep[maxn],mxdep[maxn],son[maxn];
int rub[maxn*4];
int *f[maxn],*now=rub;
int buc[maxn];
void dfs(int u,int p) {
	dep[u]=dep[p]+1;
	if (deg[u]==1) mndep[u]=0;
	else mndep[u]=1e9;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i]; if (v==p) continue;
		dfs(v,u);
		if (mxdep[v]+1>mxdep[u]) mxdep[u]=mxdep[v]+1,son[u]=v;
		mndep[u]=min(mndep[u],mndep[v]+1);
	}
}
void dfs2(int u,int p) {
	if (son[u]) buc[son[u]]=buc[u]+1;
	int m1=1e9,m2=1e9;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i]; if (v==p) continue;
		if (mndep[v]<m1) m2=m1,m1=mndep[v];
		else m2=min(m2,mndep[v]);
	}
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i]; if (v==p) continue;
		out[v]=out[u]+1;
		if (mndep[v]==m1) out[v]=min(out[v],m2+2);
		else out[v]=min(out[v],m1+2);
		dfs2(v,u);
	}
}
int x,ans;
void DFS(int u,int p) {
	if (!son[u]) {
		f[u]=now,now+=buc[u]+1;
		f[u][0]=dep[u];
		return;
	}
	DFS(son[u],u); f[u]=f[son[u]]; f[u][mxdep[u]]=-1e9;
	while (1) {
		int t=max(0,ans-m[u]-x);
		if (t<mxdep[u]&&f[u][t]+dep[u]-2*dep[u]>=ans) ans++; else break;
	}
	f[u][m[u]]=max(f[u][m[u]],dep[u]);
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i]; if (v==p||v==son[u]) continue;
		DFS(v,u);
	//	printf("v=%d\n",v);
		for (int j=0;j<=mxdep[v];j++) {
			while (1) {
				int t=max(0,ans-j-x);
				if (t<=mxdep[u]&&f[u][t]+f[v][j]-2*dep[u]>=ans) ans++; else break;
//				printf("%d %d %d %d %d\n",u,v,t,j,f[u][t]);
			}
		}
		for (int j=0;j<=mxdep[v];j++) {
			f[u][j]=max(f[u][j],f[v][j]);
		}
	}
//	for (int j=0;j<=mxdep[u];j++) printf("u=%d,j=%d %d\n",u,j,f[u][j]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=2;i<=n;i++) {
		read(x),add(x,i),add(i,x);
		deg[x]++,deg[i]++;
	}
	int rt; for (int i=1;i<=n;i++) if (deg[i]!=1) { rt=i; break; }
	tot=0;
	dfs(rt,0);
	out[rt]=1e9;
	dfs2(rt,0);
	for (int i=1;i<=n;i++) m[i]=min(out[i],mndep[i]);
	
	//for (int i=1;i<=n;i++) printf("%d ",m[i]); puts("");
	
	
	int q; read(q); while (q--) {
		now=rub;
		read(x);
		ans=0;
		DFS(rt,0);
		printf("%d ",ans-1);
	} puts("");
	return 0;
}