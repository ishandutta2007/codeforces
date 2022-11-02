#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(5e5)+10;
int n,ed[maxn];
char s[maxn];
ll ans;
ll mx[maxn*4],tr[maxn*4],sz[maxn*4],lazy[maxn*4];
int fg[maxn*4];
void build(int l,int r,int root) {
	sz[root]=r-l+1; fg[root]=-1;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
}
void putfg(int root,int delta) {
	lazy[root]=0; fg[root]=delta;
	tr[root]=sz[root]*delta;
	mx[root]=delta;
}
void putadd(int root,ll delta) {
	lazy[root]+=delta;
	mx[root]+=delta;
	tr[root]+=sz[root]*delta;
}
void pushdown(int root) {
	if (fg[root]!=-1) {
		putfg(root<<1,fg[root]);
		putfg(root<<1|1,fg[root]);
		fg[root]=-1;
	}
	if (lazy[root]) {
		putadd(root<<1,lazy[root]);
		putadd(root<<1|1,lazy[root]);
		lazy[root]=0;
	}
}
void pushup(int root) {
	mx[root]=max(mx[root<<1],mx[root<<1|1]);
	tr[root]=tr[root<<1]+tr[root<<1|1];
}
void FG(int L,int R,int l,int r,int root,int delta) {
	if (L>R) return;
	if (L<=l&&r<=R) {
		putfg(root,delta);
		return;
	}
	pushdown(root);
	int mid=(l+r)>>1;
	if (L<=mid) FG(L,R,l,mid,root<<1,delta);
	if (mid<R) FG(L,R,mid+1,r,root<<1|1,delta);
	pushup(root);
}
void ADD(int L,int R,int l,int r,int root) {
	if (L>R) return;
	if (L<=l&&r<=R) {
		putadd(root,1);
		return;
	}
	pushdown(root);
	int mid=(l+r)>>1;
	if (L<=mid) ADD(L,R,l,mid,root<<1);
	if (mid<R) ADD(L,R,mid+1,r,root<<1|1);
	pushup(root);
}
int query(int l,int r,int root,int delta) {
	if (l==r) {
		if (tr[root]>delta) return l;
		return -1;
	}
	int mid=(l+r)>>1;
	pushdown(root);
	if (mx[root<<1]>delta) return query(l,mid,root<<1,delta);
	return query(mid+1,r,root<<1|1,delta);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	scanf("%s",s+1);
	build(1,n,1);
	for (int i=n;i>=1;i--)
		if (s[i]=='1') {
			if (s[i+1]=='1') ed[i]=ed[i+1];
			else ed[i]=i;
		}
	for (int i=n;i>=1;i--) {
		if (s[i]=='1') {
			ADD(i,ed[i],1,n,1);
			int pos=query(1,n,1,ed[i]-i+1);
			if (pos==-1) pos=n+1;
			FG(ed[i]+1,pos-1,1,n,1,ed[i]-i+1);
		}
		ans+=tr[1];
	}
	printf("%lld\n",ans);
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