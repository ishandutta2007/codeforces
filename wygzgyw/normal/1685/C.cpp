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
const int maxn=(2e5)+10;
int T,n,pre[maxn],suf[maxn];
char s[maxn];
int st[maxn],tot;
struct node {
	int mx,pos;
	friend node operator + (node A,node B) { return (A.mx>B.mx?A:B); }
} tr[maxn*4],res;
int lazy[maxn*4];
void pushup(int root) { tr[root]=tr[root<<1]+tr[root<<1|1]; }
void build(int l,int r,int root) {
	lazy[root]=0;
	if (l==r) { tr[root]=(node){-suf[l+1],l}; return; }
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	pushup(root);
}
int Flag;
void puttag(int root,int delta) { lazy[root]+=delta,tr[root].mx+=delta; }
void pushdown(int root) { if (lazy[root]) puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]),lazy[root]=0; }
void add(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) { puttag(root,delta); return; }
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) add(L,R,l,mid,root<<1,delta);
	if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
	pushup(root);
}
void query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) { if (!Flag) res=tr[root]; else res=res+tr[root]; Flag=1; return; }
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) query(L,R,l,mid,root<<1);
	if (mid<R) query(L,R,mid+1,r,root<<1|1);
}
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); n*=2;
		scanf("%s",s+1);
		for (int i=1;i<=n;i++) pre[i]=(pre[i-1]+(s[i]=='('?1:-1));
		suf[n+1]=0;
		for (int i=n;i>=1;i--) suf[i]=(suf[i+1]+(s[i]=='('?1:-1));
		int flag=1;
		for (int i=1;i<=n;i++) flag&=(pre[i]>=0);
		if (flag) { puts("0"); continue; }
		int bd1,bd2;
		for (int i=1;i<=n;i++) if (pre[i]<0) { bd1=i; break; }
		for (int i=n;i>=1;i--) if (suf[i]>0) { bd2=i; break; }
		build(1,n,1);
		tot=0; st[0]=n+1;
		int X=0,Y=0;
		for (int l=n;l>=1;l--) {
			while (tot&&suf[st[tot]]>suf[l]) add(st[tot],st[tot-1]-1,1,n,1,suf[l]-suf[st[tot]]),tot--;
			add(l,l,1,n,1,suf[l]);
			st[++tot]=l;
			if (l<=bd1) {
				Flag=0;
				query(bd2,n,1,n,1);
				if (res.mx+pre[l-1]>=0) {
					X=l; Y=res.pos; break;
				}
			}
		}
		if (X) {
			printf("1\n%d %d\n",X,Y);
			reverse(s+X,s+Y+1);
		}
		else {
			X=1;
			for (int i=1;i<=n;i++) if (pre[i]>pre[X]) X=i;
			printf("2\n%d %d\n%d %d\n",1,X,X+1,n);
			reverse(s+1,s+X+1);
			reverse(s+X+1,s+n+1);
		}
	//		printf("%s\n",s+1);
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