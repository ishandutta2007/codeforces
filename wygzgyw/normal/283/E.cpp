#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n,q,d[maxn],tot;
int tr[maxn*4],lazy[maxn*4];
int sz[maxn*4],sum[maxn];
ll ans;
struct node { int x,l,r; } a[maxn*2];
bool cmp(node t1,node t2) { return t1.x<t2.x; }
void build(int l,int r,int root) {
	sz[root]=r-l+1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(l,mid,root*2);
	build(mid+1,r,root*2+1);
}
void pushdown(int root) {
	if (!lazy[root]) return;
	lazy[root*2]^=1;
	lazy[root*2+1]^=1;
	tr[root*2]=sz[root*2]-tr[root*2];
	tr[root*2+1]=sz[root*2+1]-tr[root*2+1];
	lazy[root]=0;
}
void add(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) {
		tr[root]=sz[root]-tr[root];
		lazy[root]^=1;
		return;
	}
	pushdown(root);
	int mid=(l+r)/2;
	if (L<=mid) add(L,R,l,mid,root*2);
	if (mid<R) add(L,R,mid+1,r,root*2+1);
	tr[root]=tr[root*2]+tr[root*2+1];
}
int query(int L,int R,int l,int r,int root) {
	if (L>R) return 0;
	if (L<=l&&r<=R) return tr[root];
	pushdown(root);
	int mid=(l+r)/2,res=0;
	if (L<=mid) res+=query(L,R,l,mid,root*2);
	if (mid<R) res+=query(L,R,mid+1,r,root*2+1);
	return res;
}
ll C2(ll x) { return x*(x-1)/2; }
ll C3(ll x) { return x*(x-1)*(x-2)/6; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(q);
	for (int i=1;i<=n;i++) read(d[i]);
	sort(d+1,d+n+1);
	int x,y;
	while (q--) {
		read(x); read(y);
		x=lower_bound(d+1,d+n+1,x)-d;
		y=upper_bound(d+1,d+n+1,y)-d-1;
		if (x>y) continue;
		a[++tot]=(node){x,x,y};
		a[++tot]=(node){y+1,x,y};
		//printf("flip %d %d\n",x,y);
	}
	sort(a+1,a+tot+1,cmp);
	build(1,n,1);
	int pos=0;
	for (int i=1;i<=n;i++) {
		while (pos<tot&&a[pos+1].x<=i) {
			pos++;
			add(a[pos].l,a[pos].r,1,n,1);
		}
		sum[i]=query(1,i-1,1,n,1)+(n-i)-query(i+1,n,1,n,1);
		//printf("%d\n",sum[i]);
	}
	for (int i=1;i<=n;i++) ans+=C2(n-1-sum[i]);
	printf("%lld\n",C3(n)-ans);
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