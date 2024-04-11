#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e11;
const int maxn=(1e6)+10;
int n,A,B;
ll a[maxn],b[maxn],m1,m2,ans,tmp;
struct node { int x,y,z; } d[maxn],f[maxn];
ll tr[maxn*4],lazy[maxn*4];
void build(int l,int r,int root) {
	if (l==r) { tr[root]=-b[l]; return; }
	int mid=(l+r)/2;
	build(l,mid,root*2);
	build(mid+1,r,root*2+1);
	tr[root]=max(tr[root*2],tr[root*2+1]);
}
void pushdown(int root) {
	if (lazy[root]==0) return;
	tr[root*2]+=lazy[root];
	tr[root*2+1]+=lazy[root];
	lazy[root*2]+=lazy[root];
	lazy[root*2+1]+=lazy[root];
	lazy[root]=0;
}
void add(int L,int R,int l,int r,int root,ll delta) {
	if (L>R) return;
	if (L<=l&&r<=R) {
		tr[root]+=delta;
		lazy[root]+=delta;
		return;
	}
	pushdown(root);
	int mid=(l+r)/2;
	if (L<=mid) add(L,R,l,mid,root*2,delta);
	if (mid<R) add(L,R,mid+1,r,root*2+1,delta);
	tr[root]=max(tr[root*2],tr[root*2+1]);
}
bool cmp(node t1,node t2) {
	return t1.x<t2.x;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(A);
	read(B); read(n);
	for (int i=0;i<maxn;i++) a[i]=b[i]=INF;
	for (int i=1;i<maxn*4;i++) tr[i]=-INF;
	int x,y;
	ll m1=INF,m2=INF;
	while (A--) {
		read(x); read(y);
		a[x]=min(a[x],(ll)y);
		m1=min(m1,(ll)y);
	}
	while (B--) {
		read(x); read(y);
		b[x]=min(b[x],(ll)y);
		m2=min(m2,(ll)y);
	}
	for (int i=1;i<=n;i++) read(f[i].x),read(f[i].y),read(f[i].z);
	sort(f+1,f+n+1,cmp);
	ll mn=INF+1;
	A=B=0;
	for (int i=maxn-1;i>=0;i--)
		if (a[i]!=INF) {
			if (mn<a[i]) {
				a[i]=INF;
				continue;
			}
			mn=min(mn,a[i]);
			d[++A]=(node){i,(int)a[i]};
		}
	mn=INF+1;
	for (int i=maxn-1;i>=0;i--)
		if (b[i]!=INF) {
			if (mn<b[i]) {
				b[i]=INF;
				continue;
			}
			mn=min(mn,b[i]);
		}
	build(1,maxn-1,1);
	ans=-m1-m2;
	reverse(d+1,d+A+1);
	int pos=1;
	for (int i=1;i<=A;i++) {
		x=d[i].x,y=d[i].y;
		while (f[pos].x<x&&pos<=n) {
			add(f[pos].y+1,maxn-1,1,maxn-1,1,f[pos].z);
			pos++;
		}
		tmp=tr[1]-y;
		ans=max(ans,tmp);
	}
	printf("%lld\n",ans);
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