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
const int maxn=(3e5)+10;
int n;
struct node {
	ll x,y;
	friend node operator - (node t1,node t2) { return (node){t1.x-t2.x,t1.y-t2.y}; }
	friend bool operator < (node t1,node t2) { return t1.x==t2.x?t1.y<t2.y:t1.x<t2.x; }
	friend ll operator * (node t1,node t2) { return t1.x*t2.y-t1.y*t2.x; }
	ll F(ll k) { return x*k+y; }
};
typedef vector<node> poly;
struct Node {
	node A; int l,r;
	friend bool operator < (Node t1,Node t2) { return t1.A<t2.A; }
} p[maxn];
poly tr[maxn*4];
int cnt,pos[maxn*4];
struct Query {
	int id,x,id2;
	friend bool operator < (Query t1,Query t2) { return t1.x<t2.x; }
} q[maxn]; ll ans[maxn];
void add(int L,int R,int l,int r,int root,node &A) {
	if (L<=l&&r<=R) {
		tr[root].push_back(A); return;
	}
	int mid=(l+r)>>1; if (L<=mid) add(L,R,l,mid,root<<1,A); if (mid<R) add(L,R,mid+1,r,root<<1|1,A);
}
ll query(poly &A,ll k,int &pos) {
	if ((int)A.size()==0) return -2e18;
	while (pos<(int)A.size()-1&&A[pos].F(k)<=A[pos+1].F(k)) pos++;
	return A[pos].F(k);
}
void query(int x,int l,int r,int root,ll k,ll &res) {
	res=max(res,query(tr[root],k,pos[root]));
	if (l==r) return;
	int mid=(l+r)>>1;
	if (x<=mid) query(x,l,mid,root<<1,k,res);
	else query(x,mid+1,r,root<<1|1,k,res);
}
node st[maxn]; int top;
void build(poly &A) {
	top=0;
	for (node &x : A) {
		while (top>1&&(st[top-1]-st[top])*(x-st[top])<=0) top--; st[++top]=x;
	}
	A.clear(); for (int i=1;i<=top;i++) A.push_back(st[i]);
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) {
		int op,x,y; read(op);
		if (op==1) read(x),read(y),p[i].A=(node){x,y},p[i].l=i,p[i].r=n;
		else if (op==2) read(x),p[x].r=i;
		else read(x),q[++cnt]=(Query){i,x,cnt};
	}
	sort(p+1,p+n+1);
	for (int i=1;i<=n;i++) if (p[i].r) add(p[i].l,p[i].r,1,n,1,p[i].A);
	for (int i=1;i<=n*4;i++) build(tr[i]);
	sort(q+1,q+cnt+1);
	for (int i=1;i<=cnt;i++) ans[q[i].id2]=-2e18,query(q[i].id,1,n,1,q[i].x,ans[q[i].id2]);
	for (int i=1;i<=cnt;i++) {
		if (ans[i]==-2e18) puts("EMPTY SET");
		else printf("%lld\n",ans[i]);
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