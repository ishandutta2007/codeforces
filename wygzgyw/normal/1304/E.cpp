#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,m,q,tot,nxt[maxn*2],head[maxn],to[maxn*2];
int dep[maxn],fa[maxn][20],bg[maxn],ed[maxn];
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
void dfs(int u,int p) {
	bg[u]=++tot;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p) continue;
		dep[v]=dep[u]+1;
		fa[v][0]=u;
		dfs(v,u);
	}
	ed[u]=tot;
}
int lca(int x,int y) {
	if (dep[x]>dep[y]) swap(x,y);
	for (int i=19;i>=0;i--)
		if (fa[y][i]&&dep[fa[y][i]]>=dep[x])
			y=fa[y][i];
	if (x==y) return x;
	for (int i=19;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dis(int x,int y,int z) {
	return dep[x]+dep[y]-2*dep[z];
}
int dis(int x,int y) {
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
bool solve(int x) {
	if (x<=m&&(m-x)%2==0) return 1;
	return 0;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	int x,y,a,b,flag,z,dxy,t1,t2,t3,t4;
	for (int i=1;i<n;i++) {
		read(x); read(y);
		add(x,y);
		add(y,x);
	}
	tot=0;
	dfs(1,0);
	for (int j=1;j<=19;j++)
	for (int i=1;i<=n;i++)
		fa[i][j]=fa[fa[i][j-1]][j-1];
	read(q);
	for (int I=1;I<=q;I++) {
		read(x); read(y);
		read(a); read(b);
		read(m);
		if (solve(dis(a,b))) { printf("YES\n"); continue; }
		z=lca(x,y);
		dxy=dis(x,y,z);
		if (solve(dis(a,x)+1+dis(y,b))) { printf("YES\n"); continue; }
		if (solve(dis(a,y)+1+dis(x,b))) { printf("YES\n"); continue; }
		if (bg[z]<=bg[a]&&bg[a]<=ed[z]) {
			t1=lca(a,x); t3=dis(a,t1,t1);
			t2=lca(a,y); t4=dis(a,t2,t2);
			if (solve(t3+dxy+1+dis(t1,b))) { printf("YES\n"); continue; }
			if (solve(t4+dxy+1+dis(t2,b))) { printf("YES\n"); continue; }		
		} else {
			if (solve(dis(a,z)+dxy+1+dis(z,b))) { printf("YES\n"); continue; }
		}
		swap(a,b);
		if (bg[z]<=bg[a]&&bg[a]<=ed[z]) {
			t1=lca(a,x); t3=dis(a,t1,t1);
			t2=lca(a,y); t4=dis(a,t2,t2);
			if (solve(t3+dxy+1+dis(t1,b))) { printf("YES\n"); continue; }
			if (solve(t4+dxy+1+dis(t2,b))) { printf("YES\n"); continue; }		
		} else {
			if (solve(dis(a,z)+dxy+1+dis(z,b))) { printf("YES\n"); continue; }
		}
		printf("NO\n");
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