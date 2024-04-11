#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=0x7f7f7f7f;
const int maxn=(3e5)+10;
const int maxm=(1e7)+10;
int n,m,q,tot,tr[maxm],ls[maxm],rs[maxm],rt[maxn];
struct node {
	int l,r,id;
} d[maxn];
bool cmp(node a,node b) { return a.l<b.l; }
void add(int x,int l,int r,int &root,int delta) {
	tot++; tr[tot]=tr[root];
	ls[tot]=ls[root]; rs[tot]=rs[root];
	root=tot;
	if (l==r) { tr[root]=min(tr[root],delta); return; }
	int mid=(l+r)/2;
	if (x<=mid) add(x,l,mid,ls[root],delta);
	else add(x,mid+1,r,rs[root],delta);
	tr[root]=max(tr[ls[root]],tr[rs[root]]);
}
int query(int L,int R,int l,int r,int root) {
	if (!root) return INF;
	if (L<=l&&r<=R) return tr[root];
	int mid=(l+r)/2,res=0;
	if (L<=mid) res=max(res,query(L,R,l,mid,ls[root]));
	if (mid<R) res=max(res,query(L,R,mid+1,r,rs[root]));
	return res;
}
int main() {
	//printf("MLE %d\n",(sizeof(tr)+sizeof(ls)+sizeof(rs)+sizeof(rt)+sizeof(d))/1024/1024);
	//freopen("1.txt","r",stdin);
	read(n); read(q); read(m);
	for (int i=1;i<=m;i++) read(d[i].l),read(d[i].r),read(d[i].id);
	sort(d+1,d+m+1,cmp);
	memset(tr,INF,sizeof(tr));
	for (int i=m;i>=1;i--) {
		rt[i]=rt[i+1];
		add(d[i].id,1,n,rt[i],d[i].r);
	}
	//for (int i=1;i<=m;i++) printf("%d %d %d\n",d[i].l,d[i].r,d[i].id);
	int a,b,x,y,l,r,mid,res;
	while (q--) {
		read(a); read(b); read(x); read(y);
		if (d[m].l<x) { printf("no\n"); fflush(stdout); continue; }
		l=1,r=m;
		while (l<=r) {
			mid=(l+r)/2;
			if (d[mid].l>=x) res=mid,r=mid-1;
			else l=mid+1;
		}
		res=query(a,b,1,n,rt[res]);
		if (res<=y) printf("yes\n");
		else printf("no\n");
		fflush(stdout);
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/