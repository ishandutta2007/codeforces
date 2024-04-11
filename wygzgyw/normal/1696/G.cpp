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
int n,q,x,y,b[maxn];
bool flag;
struct Matrix {
	double d[3][3];
	friend Matrix operator + (Matrix t1,Matrix t2) {	
		Matrix res;
		for (int i=0;i<3;i++) for (int j=0;j<3;j++) {
			res.d[i][j]=max(t1.d[i][0],t1.d[i][1])+max(t2.d[0][j],t2.d[1][j]);
			res.d[i][j]=max(res.d[i][j],max(t1.d[i][0]+t2.d[2][j],t1.d[i][2]+t2.d[0][j]));
		}
		return res;
	}
	void init(int A) {
		for (int i=0;i<3;i++) for (int j=0;j<3;j++) d[i][j]=-1e16;
		d[0][0]=0,d[1][1]=A*1.0/(x+y),d[2][2]=A*1.0/y;
	}
} tr[maxn*4],res;
void build(int l,int r,int root) {
	if (l==r) { tr[root].init(b[l]); return; }
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	tr[root]=(tr[root<<1]+tr[root<<1|1]);
}
void query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) { if (!flag) res=tr[root]; else res=res+tr[root]; flag=1; return; }
	int mid=(l+r)>>1;
	if (L<=mid) query(L,R,l,mid,root<<1);
	if (mid<R) query(L,R,mid+1,r,root<<1|1);
}
void change(int x,int l,int r,int root) {
	if (l==r) { tr[root].init(b[l]); return; }
	int mid=(l+r)>>1;
	if (x<=mid) change(x,l,mid,root<<1);
	else change(x,mid+1,r,root<<1|1);
	tr[root]=(tr[root<<1]+tr[root<<1|1]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q);
	read(x),read(y);
	if (x>y) swap(x,y);
	for (int i=1;i<=n;i++) read(b[i]);
	build(1,n,1);
	while (q--) {
		int op,l,r;
		read(op),read(l),read(r);
		if (op==1) b[l]=r,change(l,1,n,1);
		else {
			flag=0;
			query(l,r,1,n,1);
			double mx=0;
			for (int i=0;i<3;i++) for (int j=0;j<3;j++) mx=max(mx,res.d[i][j]);
			printf("%.11lf\n",mx);
		}
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