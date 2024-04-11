#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int n,d[maxn],pos[maxn];
ll tr[maxn*4],s[maxn],a[maxn],lazy[maxn*4],ans,sum,tmp;
void build(int l,int r,int root) {
	if (l==r) { tr[root]=s[l]; return; }
	int mid=(l+r)/2;
	build(l,mid,root*2);
	build(mid+1,r,root*2+1);
	tr[root]=min(tr[root*2],tr[root*2+1]);
}
void pushdown(int root) {
	if (!lazy[root]) return;
	lazy[root*2]+=lazy[root];
	lazy[root*2+1]+=lazy[root];
	tr[root*2]+=lazy[root];
	tr[root*2+1]+=lazy[root];
	lazy[root]=0;
}
void update(int L,int R,int l,int r,int root,ll delta) {
	if (L>R) return;
	//printf("A %d %d %lld\n",L,R,delta);
	if (L<=l&&r<=R) {
		tr[root]+=delta;
		lazy[root]+=delta;
		return;
	}
	int mid=(l+r)/2;
	pushdown(root);
	if (L<=mid) update(L,R,l,mid,root*2,delta);
	if (mid<R) update(L,R,mid+1,r,root*2+1,delta);
	tr[root]=min(tr[root*2],tr[root*2+1]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(d[i]),pos[d[i]]=i;
	for (int i=1;i<=n;i++) read(a[i]),s[i]=a[i]+s[i-1];
	build(1,n-1,1);
	int x;
	ans=1LL<<50;
	for (int i=1;i<=n;i++) {
		x=pos[i];
		sum+=a[x];
		update(x,n-1,1,n-1,1,-a[x]*2);
		tmp=sum+tr[1];
		ans=min(ans,tmp);
	}
	ans=min(ans,min(a[1],a[n]));
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