#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,head[maxn],tot,nxt[maxn*2],to[maxn*2];
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
int dep[maxn],bg[maxn],ed[maxn],dy[maxn];
void dfs1(int u,int p) {
	bg[u]=++tot;
	dep[u]=dep[p]^1;
	dy[tot]=u;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p) continue;
		dfs1(v,u);
	}
	ed[u]=tot;
}
int tr[maxn*4],sz[maxn*4],lazy[maxn*4];
void pushup(int root) {
	tr[root]=tr[root*2]+tr[root*2+1];
}
void build(int l,int r,int root) {
	sz[root]=r-l+1;
	if (l==r) {
		tr[root]=dep[dy[l]];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,root*2);
	build(mid+1,r,root*2+1);
	pushup(root);
}
/*
void add(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) {
		tr[root]=sz[root]-tr[root];
		lazy[root]=1;
		return;
	}
	pushdown(root);
	int mid=(l+r)/2;
	if (L<=mid) add(L,R,l,mid,root*2);
	if (mid<R) add(L,R,mid+1,r,root*2+1);
	pushup(root);
}*/
int main() {
	//freopen("1.txt","r",stdin);
	read(n); int x,y;
	for (int i=1;i<n;i++) {
		read(x); read(y);
		add(x,y); add(y,x);
	}
	tot=0;
	dfs1(1,0);
	build(1,n,1);
	int ans=tr[1];
	printf("%d\n",min(ans,n-ans)-1);
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