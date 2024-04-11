#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(6e5)+10;
int n,m,q;
int a[maxn];
vector<int> h[maxn];
int fa[maxn],sz[maxn];
bool del[maxn],vis[maxn];
int ex[maxn],ey[maxn],bel[maxn];
struct node { int op,x,rx,ry; } Q[maxn];
int find(int x) {
	if (fa[x]==x) return x;
	return find(fa[x]);
}
int query(int x) {
	while (h[x].size()&&(bel[h[x].back()]!=x||vis[h[x].back()])) h[x].pop_back();
	if (!h[x].size()) return 0;
	int u=h[x].back();
	h[x].pop_back();
	vis[u]=1;
	return u;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m),read(q);
	
	for (int i=1;i<=n;i++) {
		read(a[i]); h[i].push_back(a[i]);
		sz[i]=1,fa[i]=i;
	}
	for (int i=1;i<=m;i++) read(ex[i]),read(ey[i]);
	for (int i=1;i<=q;i++) {
		read(Q[i].op),read(Q[i].x);
		if (Q[i].op==2) del[Q[i].x]=1;
	}
	int x,y;
	for (int i=1;i<=m;i++) if (!del[i]) {
		x=find(ex[i]),y=find(ey[i]);
		if (x==y) continue;
		if (sz[x]>sz[y]) swap(x,y);
		for (int j : h[x]) h[y].push_back(j);
		fa[x]=y,sz[y]+=sz[x];
	}
	for (int i=q;i>=1;i--) if (Q[i].op==2) {
		x=ex[Q[i].x],y=ey[Q[i].x];
		x=find(x),y=find(y);
		if (x==y) continue;
		if (sz[x]>sz[y]) swap(x,y);
		Q[i].rx=x,Q[i].ry=y;
		fa[x]=y,sz[y]+=sz[x];
		sort(h[x].begin(),h[x].end());
		for (int j : h[x]) h[y].push_back(j);
	}
	for (int i=1;i<=n;i++) {
		bel[a[i]]=find(i);
		sort(h[i].begin(),h[i].end());
	}
	for (int i=1;i<=q;i++) {
		if (Q[i].op==1) printf("%d\n",query(find(Q[i].x)));
		else {
			x=Q[i].rx;
			for (int j : h[x]) bel[j]=x;
			fa[x]=x;
		}
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