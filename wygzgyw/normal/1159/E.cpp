#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9);
const int maxn=(5e5)+10;
int T,n,a[maxn],ans[maxn];
int tr[maxn*4],tot,u,lazy[maxn*4];
queue<int> q;
int head[maxn],nxt[maxn],to[maxn];
void pushdown(int root) {
	tr[root*2]+=lazy[root];
	tr[root*2+1]+=lazy[root];
	lazy[root*2]+=lazy[root];
	lazy[root*2+1]+=lazy[root];
	lazy[root]=0;
}
void add(int L,int R,int l,int r,int root,int delta) {
	if (L>R) return;
	if (L<=l&&r<=R) {
		tr[root]+=delta; lazy[root]+=delta;
		//printf("%d %d %d %d %d %d\n",L,R,l,r,delta,tr[root]);
		if (tr[root]>0||delta!=-1) return;
		tr[root]-=delta; lazy[root]-=delta;
		if (l==r) { q.push(l); tr[root]=INF; return; }
	}
	pushdown(root);
	int mid=(l+r)/2;
	if (L<=mid) add(L,R,l,mid,root*2,delta);
	if (mid<R) add(L,R,mid+1,r,root*2+1,delta);
	tr[root]=min(tr[root*2],tr[root*2+1]);
}
int query(int x,int l,int r,int root) {
	if (l==r) { return tr[root]; }
	pushdown(root);
	int mid=(l+r)/2;
	if (x<=mid) return query(x,l,mid,root*2);
	return query(x,mid+1,r,root*2+1);
}
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); tot=0;
		for (int i=1;i<=n*4;i++) tr[i]=lazy[i]=0;
		for (int i=1;i<=n;i++) head[i]=0;
		//printf("%d\n",tr[4]);
		//printf("%d\n%d\n",tr[4],query(1,1,n,1));
		for (int i=1;i<=n;i++) {
			read(a[i]);
			if (a[i]!=-1) {
				if (a[i]<=n) add(i,a[i]-1,1,n,1,1),add(a[i],i);
				else add(i+1,a[i]-1,1,n,1,1);
			}
		} tot=0;
		for (int i=1;i<=n;i++)
			if (query(i,1,n,1)==0) q.push(i),add(i,i,1,n,1,INF);
		while (!q.empty()) {
			u=q.front(); q.pop(); ans[u]=++tot;
			//printf("%d %d\n",u,tot);
			//printf("%d\n",query(3,1,n,1));
			if (a[u]!=-1) {
				if (a[u]<=n) add(u,a[u]-1,1,n,1,-1);
				else add(u+1,a[u]-1,1,n,1,-1);
			}
			for (int i=head[u];i;i=nxt[i])
				add(to[i],to[i],1,n,1,-1);
		}
		if (tot<n) printf("-1\n");
		else {
			//printf(":\n");
			for (int i=1;i<=n;i++) printf("%d ",n-ans[i]+1);
			printf("\n");
		}
	}
	return 0;
}