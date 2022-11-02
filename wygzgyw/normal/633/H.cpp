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
const int maxn=30010;
int n,mod,block,q,a[maxn],lsh[maxn],N,b[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
struct node {
	int d[2][2],A,B;
	friend node operator + (node &t1,node &t2) {
		node res;
		for (int i=0;i<2;++i) for (int j=0;j<2;++j) {
			res.d[i][j]=(t1.d[i][0]*t2.d[0][j]+t1.d[i][1]*t2.d[1][j])%mod;
		}
		res.A=(t1.A+t1.d[0][0]*t2.A+t1.d[0][1]*t2.B)%mod;
		res.B=(t1.B+t1.d[1][0]*t2.A+t1.d[1][1]*t2.B)%mod;
		return res;
	}
} tr[maxn*8];
struct Query {
	int l,r,id;
} Q[maxn];
bool cmp(Query A,Query B) {
	if (A.l/block==B.l/block) return A.r<B.r;
	return A.l<B.l;
}
int buc[maxn],ans[maxn],sz;

void modify(int x,int l,int r,int root,int delta) {
	root=x+sz-1;
	node &A=tr[root];
	if (delta==1) {
		A.d[0][0]=0,A.d[1][0]=1;
		A.d[0][1]=A.d[1][1]=1;
		A.A=0,A.B=lsh[x]%mod;
	} else {
		A.d[0][0]=A.d[1][1]=1;
		A.d[0][1]=A.d[1][0]=0;
		A.A=A.B=0;
	}
	root>>=1;
	for (;root;root>>=1) {
		tr[root]=tr[root<<1]+tr[root<<1|1];
	}
}
void insert(int x) {
	buc[x]++; if (buc[x]==1) modify(x,1,N,1,1);
}
void del(int x) {
	buc[x]--; if (!buc[x]) modify(x,1,N,1,-1);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(mod);
	for (int i=1;i<=n;i++) read(a[i]),lsh[++N]=a[i];
	sort(lsh+1,lsh+N+1),N=unique(lsh+1,lsh+N+1)-lsh-1;
	for (int i=1;i<=n;i++) b[i]=lower_bound(lsh+1,lsh+N+1,a[i])-lsh;
	sz=N; sz=sz&(sz-1)?2<<__lg(sz):sz;
	read(q);
	block=(int)sqrt((n+q)*1.4); block=max(block,1);
	for (int i=1;i<=q;i++) read(Q[i].l),read(Q[i].r),Q[i].id=i;
	for (int i=1;i<=N;i++) modify(i,1,N,1,-1);
	sort(Q+1,Q+q+1,cmp);
	int l=1,r=0;
	for (int i=1;i<=q;i++) {
		while (r<Q[i].r) r++,insert(b[r]);
		while (r>Q[i].r) del(b[r]),r--;
		while (l<Q[i].l) del(b[l]),l++;
		while (l>Q[i].l) l--,insert(b[l]);
		ans[Q[i].id]=tr[1].B;
		//printf("query > %d\n",tr[1].B);
	}
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
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