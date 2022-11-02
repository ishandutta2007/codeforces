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
const int INF=1e9;
const int maxn=(1e5)+10;
int n,q; char s[maxn];
struct Matrix {
int d[3][3];
friend Matrix operator * (Matrix t1,Matrix t2) {
	Matrix res; for (int i=0;i<3;i++) for (int j=0;j<3;j++) {
		res.d[i][j]=INF;
		for (int k=0;k<3;k++) res.d[i][j]=min(res.d[i][j],t1.d[i][k]+t2.d[k][j]);
	} return res;
}
void init(int x) {
	for (int i=0;i<3;i++) for (int j=0;j<3;j++) d[i][j]=INF;
	if (x==0) {
		d[0][0]=1,d[0][1]=0;
		d[1][1]=0,d[2][2]=0,d[1][2]=1;
	} else if (x==1) {
		d[0][0]=0,d[0][1]=1;
		d[1][2]=0,d[1][1]=1;
		d[2][2]=0;
	} else {
		d[0][0]=0,d[0][1]=0;
		d[1][1]=0,d[2][2]=1;
	}
}
} tr[maxn*4];
void init(int root,int now) {
	tr[root].init(now);
}
void build(int l,int r,int root) {
	if (l==r) { init(root,s[l]-'a'); return; }
	int mid=(l+r)>>1; build(l,mid,root<<1),build(mid+1,r,root<<1|1); tr[root]=tr[root<<1]*tr[root<<1|1];
}
void change(int x,int l,int r,int root,int delta) {
	if (l==r) { init(root,delta); return; }
	int mid=(l+r)>>1; if (x<=mid) change(x,l,mid,root<<1,delta); else change(x,mid+1,r,root<<1|1,delta);
	tr[root]=tr[root<<1]*tr[root<<1|1];
}
int main() {
	read(n),read(q);
	scanf("%s",s+1);
	build(1,n,1);
	while (q--) {
		int pos; char t[10]; read(pos); scanf("%s",t+1);
		change(pos,1,n,1,t[1]-'a');
		printf("%d\n",min(min(tr[1].d[0][0],tr[1].d[0][1]),tr[1].d[0][2]));
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