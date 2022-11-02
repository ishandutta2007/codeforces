#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(3e5)+10;
const ll INF=1e18;
int n,h[maxn],b[maxn],tot,d[maxn];
ll dp[maxn],rem[maxn];
multiset<ll> s;

namespace Seg {
	ll tr[maxn*4];
	void pushup(int root) {
		tr[root]=max(tr[root<<1],tr[root<<1|1]);
	}
	void build(int l,int r,int root) {
		if (l==r) {
			if (l==0) tr[root]=0;
			else tr[root]=-INF;
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,root<<1),build(mid+1,r,root<<1|1);
		pushup(root);
	}
	void insert(int x,int l,int r,int root) {
		if (l==r) { tr[root]=dp[x]; return; }
		int mid=(l+r)>>1;
		if (x<=mid) insert(x,l,mid,root<<1);
		else insert(x,mid+1,r,root<<1|1);
		pushup(root);
	}
	ll query(int L,int R,int l,int r,int root) {
		if (L<=l&&r<=R) return tr[root];
		int mid=(l+r)>>1; ll res=-INF;
		if (L<=mid) res=query(L,R,l,mid,root<<1);
		if (mid<R) res=max(res,query(L,R,mid+1,r,root<<1|1));
		return res;
	}
};
multiset<ll>::iterator it;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(h[i]);
	for (int i=1;i<=n;i++) read(b[i]);
	Seg::build(0,n,1);
	for (int i=1;i<=n;i++) {
		while (tot&&h[d[tot]]>h[i]) s.erase(s.find(rem[tot])),tot--;
		d[++tot]=i;
		rem[tot]=Seg::query(d[tot-1],i-1,0,n,1)+b[i];
		s.insert(rem[tot]);
		it=s.end(); it--;
		dp[i]=(*it);
		Seg::insert(i,0,n,1);
	}
	printf("%lld\n",dp[n]);
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