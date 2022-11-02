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
const int INF=1e8;
const int maxn=(5e5)+10;
int n,a[maxn],id[maxn],bk[maxn];
bool cmp(int x,int y) { return a[x]<a[y]; }
namespace BIT {
int tr[maxn];
void add(int x,int delta) {
	for (;x<=n;x+=x&(-x)) tr[x]+=delta;
}
int query(int x) {
	int res=0; for (;x;x-=x&(-x)) res+=tr[x]; return res;
}
};
namespace T1 { // T1
int lazy[maxn*4],tr[maxn*4];
void pushup(int root) { tr[root]=max(tr[root<<1],tr[root<<1|1]); }
void build(int l,int r,int root) {
	if (l==r) { tr[root]=-INF-a[id[l]]; return; }
	int mid=(l+r)>>1; build(l,mid,root<<1),build(mid+1,r,root<<1|1); pushup(root);
}
void puttag(int root,int delta) { lazy[root]+=delta,tr[root]+=delta; }
void pushdown(int root) { if (lazy[root]) puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]),lazy[root]=0; }
void add(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) { puttag(root,delta); return; }
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) add(L,R,l,mid,root<<1,delta);
	if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
	pushup(root);
}
int query(int L,int R,int l,int r,int root) {
	if (tr[root]!=1) return n+1;
	if (L<=l&&r<=R) {
		if (l==r) return l;
		pushdown(root);
		int mid=(l+r)>>1;
		if (tr[root<<1]==1) return query(L,R,l,mid,root<<1);
		return query(L,R,mid+1,r,root<<1|1);
	}
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) {
		int res=query(L,R,l,mid,root<<1);
		if (res!=n+1) return res;
	}
	if (mid<R) return query(L,R,mid+1,r,root<<1|1);
	return n+1;
}
};
namespace T2 { // T-1
int lazy[maxn*4],tr[maxn*4];
void pushup(int root) { tr[root]=min(tr[root<<1],tr[root<<1|1]); }
void build(int l,int r,int root) {
	if (l==r) { tr[root]=INF-a[id[l]]; return; }
	int mid=(l+r)>>1; build(l,mid,root<<1),build(mid+1,r,root<<1|1); pushup(root);
}
void puttag(int root,int delta) { lazy[root]+=delta,tr[root]+=delta; }
void pushdown(int root) { if (lazy[root]) puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]),lazy[root]=0; }
void add(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) { puttag(root,delta); return; }
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) add(L,R,l,mid,root<<1,delta);
	if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
	pushup(root);
}
int query(int L,int R,int l,int r,int root) {
	if (tr[root]!=-1) return n+1;
	if (L<=l&&r<=R) {
		if (l==r) return l;
		pushdown(root);
		int mid=(l+r)>>1;
		if (tr[root<<1]==-1) return query(L,R,l,mid,root<<1);
		return query(L,R,mid+1,r,root<<1|1);
	}
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) {
		int res=query(L,R,l,mid,root<<1);
		if (res!=n+1) return res;
	}
	if (mid<R) return query(L,R,mid+1,r,root<<1|1);
	return n+1;
}
};
set<int> s;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),id[i]=i;
	sort(id+1,id+n+1,cmp); for (int i=1;i<=n;i++) bk[id[i]]=i;
	T1::build(1,n,1),T2::build(1,n,1);
	//for (int i=1;i<=n;i++) printf("%d ",id[i]); puts("");
	//for (int i=1;i<=n;i++) printf("%d ",a[id[i]]); puts("");
	for (int i=1;i<=n;i++) {
		int x=bk[i];
		int r=BIT::query(x),pos;
		if (r<a[i]) { // +1
			//printf("%d %d %d\n",a[i],i,1);
			BIT::add(x,1); T1::add(x,x,1,n,1,INF);
			T1::add(x,n,1,n,1,1); T2::add(x,n,1,n,1,1);
			pos=T1::query(x,n,1,n,1);
			set<int>::iterator it=s.lower_bound(x);
			if (it!=s.end()&&(*it)<pos) {
				pos=(*it); s.erase(pos);
				T1::add(pos,n,1,n,1,-1),T2::add(pos,n,1,n,1,-1);
				T2::add(pos,pos,1,n,1,-INF); BIT::add(pos,-1);
			//	printf("change %d %d %d\n",a[id[pos]],id[pos],-1);
			} else if (pos<=n) {
				T1::add(pos,n,1,n,1,-1); T1::add(pos,pos,1,n,1,-INF);
				T2::add(pos,n,1,n,1,-1); BIT::add(pos,-1); s.insert(pos);
			//	printf("change %d %d %d\n",a[id[pos]],id[pos],0);
			}
		} else if (r>a[i]) { // -1
			//printf("%d %d %d\n",a[i],i,-1);
			BIT::add(x,-1); T2::add(x,x,1,n,1,-INF);
			T1::add(x,n,1,n,1,-1); T2::add(x,n,1,n,1,-1);
			pos=T2::query(x,n,1,n,1);
			set<int>::iterator it=s.lower_bound(x);
			if (it!=s.end()&&(*it)<pos) {
				pos=(*it); s.erase(pos);
				T1::add(pos,n,1,n,1,1),T2::add(pos,n,1,n,1,1);
				T1::add(pos,pos,1,n,1,INF); BIT::add(pos,1);
				//printf("change %d %d %d\n",a[id[pos]],id[pos],1);
			} else if (pos<=n) {
				T1::add(pos,n,1,n,1,1); T2::add(pos,pos,1,n,1,INF);
				T2::add(pos,n,1,n,1,1); BIT::add(pos,1); s.insert(pos);
				//printf("change %d %d %d\n",a[id[pos]],id[pos],0);
			}
		} else s.insert(x);//,printf("%d %d %d\n",a[i],i,0);
		printf("%d\n",BIT::query(n));
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