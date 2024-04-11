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
typedef long long ll;
const ll INF=1e18;
const int maxn=(3e5)+10;
int T,n,fa[maxn],dep[maxn];
ll a[maxn],s1[maxn],s2[maxn],ans;
map<ll,int> lst;

namespace T1 {
	ll tr[maxn*4];
	void build(int l,int r,int root) {
		if (l==r) { if (l&1) tr[root]=s1[l]; else tr[root]=INF; return; }
		int mid=(l+r)>>1;
		build(l,mid,root<<1),build(mid+1,r,root<<1|1);
		tr[root]=min(tr[root<<1],tr[root<<1|1]);
	}
	int query(int L,int R,int l,int r,int root,ll delta) {
		if (tr[root]-delta>=0) return n+1;
		int mid=(l+r)>>1;
		if (L<=l&&r<=R) {
			if (l==r) return l;
			if (tr[root<<1]-delta>=0) return query(L,R,mid+1,r,root<<1|1,delta);
			return query(L,R,l,mid,root<<1,delta);
		}
		int res=n+1;
		if (L<=mid) res=query(L,R,l,mid,root<<1,delta);
		if (res==n+1&&mid<R) res=query(L,R,mid+1,r,root<<1|1,delta); return res;
	}
};
namespace T2 {
	ll tr[maxn*4];
	void build(int l,int r,int root) {
		if (l==r) { if (l&1^1) tr[root]=s2[l]; else tr[root]=INF; return; }
		int mid=(l+r)>>1;
		build(l,mid,root<<1),build(mid+1,r,root<<1|1);
		tr[root]=min(tr[root<<1],tr[root<<1|1]);
	}
	int query(int L,int R,int l,int r,int root,ll delta) {
		if (tr[root]-delta>=0) return n+1;
		int mid=(l+r)>>1;
		if (L<=l&&r<=R) {
			if (l==r) return l;
			if (tr[root<<1]-delta>=0) return query(L,R,mid+1,r,root<<1|1,delta);
			return query(L,R,l,mid,root<<1,delta);
		}
		int res=n+1;
		if (L<=mid) res=query(L,R,l,mid,root<<1,delta);
		if (res==n+1&&mid<R) res=query(L,R,mid+1,r,root<<1|1,delta); return res;
	}
};
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) {
			read(a[i]);
			s1[i]=s1[i-1]+a[i]*(i%2==1?1:-1);
			s2[i]=s2[i-1]+a[i]*(i%2==0?1:-1);
		}
		T1::build(1,n,1),T2::build(1,n,1); lst.clear();
		for (int i=n;i>=1;i--) {
			lst[s1[i]]=i;
			int pos=lst[s1[i-1]],bd;
			bd=min(T1::query(i,n,1,n,1,s1[i-1])-1,T2::query(i,n,1,n,1,s2[i-1])-1);
			if (pos&&pos<=bd) {
				fa[i]=pos;
			} else fa[i]=n+1;
		}
	//	for (int i=1;i<=n;i++) printf("fa[%d]=%d\n",i,fa[i]);
		for (int i=1;i<=n+1;i++) dep[i]=0;
		ans=0;
		for (int i=n;i>=1;i--) if (fa[i]!=n+1) dep[i]=dep[fa[i]+1]+1,ans+=dep[i];
		printf("%lld\n",ans);
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/