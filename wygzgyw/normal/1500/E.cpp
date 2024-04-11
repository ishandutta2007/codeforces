#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(4e5)+10;
int n,q,N;
ll Q[maxn],x,a[maxn],lsh[maxn];
int tr[maxn*4],lazy[maxn*4],idex;
ll sum[maxn*4],s2[maxn*4],allsum,ans;
int all,mk[maxn];
void puttag(int root,int delta) {
	s2[root]+=sum[root]*delta;
	lazy[root]+=delta;
}
void pushdown(int root) {
	if (lazy[root]) {
		puttag(root<<1,lazy[root]);
		puttag(root<<1|1,lazy[root]);
		lazy[root]=0;
	}
}
void pushup(int root) {
	tr[root]=tr[root<<1]+tr[root<<1|1];
	sum[root]=sum[root<<1]+sum[root<<1|1];
	s2[root]=s2[root<<1]+s2[root<<1|1];
}
void build(int l,int r,int root) {
	if (l==r) {
		if (mk[l]) {
			idex++;
			tr[root]=1;
			sum[root]=lsh[l];
			s2[root]=(ll)lsh[l]*idex;
			//printf("? %d\n",l);
		}
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	pushup(root);
}
void ADD(int L,int R,int l,int r,int root,int delta) {
	if (L>R) return;	
	if (L<=l&&r<=R) {
		puttag(root,delta);
		return;
	}
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) ADD(L,R,l,mid,root<<1,delta);
	if (mid<R) ADD(L,R,mid+1,r,root<<1|1,delta);
	pushup(root);
}
void add(int x,int l,int r,int root,int delta) {
	if (l==r) {
		if (delta==1) tr[root]=1,sum[root]=lsh[x],s2[root]=(ll)idex*lsh[x];
		else tr[root]=sum[root]=s2[root]=0;
		return;
	}
	int mid=(l+r)>>1; pushdown(root);
	if (x<=mid) add(x,l,mid,root<<1,delta);
	else add(x,mid+1,r,root<<1|1,delta);
	pushup(root);
}
int querynum(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) return tr[root];
	pushdown(root); int mid=(l+r)>>1,res=0;
	if (L<=mid) res=querynum(L,R,l,mid,root<<1);
	if (mid<R) res+=querynum(L,R,mid+1,r,root<<1|1);
	return res;
}
ll querysum(int k,int l,int r,int root) {
	if (l==r) return sum[root];
	int mid=(l+r)>>1; pushdown(root);
	if (tr[root<<1]>=k) return querysum(k,l,mid,root<<1);
	return sum[root<<1]+querysum(k-tr[root<<1],mid+1,r,root<<1|1);
}
ll querys2(int k,int l,int r,int root) {
	if (!k) return 0;
	if (l==r) return s2[root];
	int mid=(l+r)>>1; pushdown(root);
	if (tr[root<<1]>=k) return querys2(k,l,mid,root<<1);
	return s2[root<<1]+querys2(k-tr[root<<1],mid+1,r,root<<1|1);
}
ll querysum2(int k,int l,int r,int root) {
	if (!k) return 0;
	if (l==r) return sum[root];
	int mid=(l+r)>>1; pushdown(root);
	if (tr[root<<1|1]>=k) return querysum2(k,mid+1,r,root<<1|1);
	return sum[root<<1|1]+querysum2(k-tr[root<<1|1],l,mid,root<<1);
}
ll querys22(int k,int l,int r,int root) {
	if (!k) return 0;
	if (l==r) return s2[root];
	int mid=(l+r)>>1; pushdown(root);
	if (tr[root<<1|1]>=k) return querys22(k,mid+1,r,root<<1|1);
	return s2[root<<1|1]+querys22(k-tr[root<<1|1],l,mid,root<<1);
}
ll F(int k) {
	return querysum(k+1,1,N,1)+querysum(all-k,1,N,1)-allsum;
}
void solve() {
	//printf("%lld %lld\n",F(0),querysum(all,1,N,1));
	//return;
	int l=0,r=(all-1)/2,mid,res=0;
	while (l<=r) {
		mid=(l+r)>>1;
		if (F(mid)>=0) res=mid,l=mid+1;
		else r=mid-1;
	}
	//printf("res=%d %lld %lld %lld\n",res,F(0),F(1),querysum(res,1,N,1));
	ans=(ll)querysum(res+1,1,N,1)*(res+2)-querys2(res+1,1,N,1);
	//printf("%lld\n",ans);
	ans-=(ll)querysum2(res,1,N,1)*(res-all)+querys22(res,1,N,1);
	//printf("%lld\n",ans);
	ans*=2;
	if (res==all-1-res) ans-=F(res);
	printf("%lld\n",allsum-ans);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q);
	for (int i=1;i<=n;i++) {
		read(x),a[i]=x; lsh[++N]=x;
	}
	int op;
	for (int i=1;i<=q;i++) {
		read(op),read(x); lsh[++N]=x;
		if (op==2) x=-x;
		Q[i]=x;
	}
	sort(lsh+1,lsh+N+1),N=unique(lsh+1,lsh+N+1)-lsh-1;
	for (int i=1;i<=n;i++) mk[lower_bound(lsh+1,lsh+N+1,a[i])-lsh]=1,allsum+=a[i];
	//for (int i=1;i<=N;i++) printf("%lld ",lsh[i]); puts("");
	build(1,N,1); all=n;
	solve();
	int y;
	for (int i=1;i<=q;i++) {
		x=Q[i]; y=lower_bound(lsh+1,lsh+N+1,abs(x))-lsh;
		allsum+=x;
		if (x>0) {
			all++;
			idex=querynum(1,y,1,N,1)+1;
			add(y,1,N,1,1);
			ADD(y+1,N,1,N,1,1);
		} else {
			all--;
			add(y,1,N,1,-1);
			ADD(y+1,N,1,N,1,-1);
		}
		solve();
		//exit(0);
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