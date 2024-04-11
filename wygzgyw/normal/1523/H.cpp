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
const int maxn=20010;
int n,m;
int a[maxn];
int st[maxn][16];
int lg[maxn],f[maxn][16][32];
int MX(int x,int y) {
	if (a[x]+x>a[y]+y) return x; return y;
}
int query(int x,int y) {
	int j=lg[y-x+1];
	return MX(st[x][j],st[y-(1<<j)+1][j]);
}
int A[32],B[32];
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	for (int i=1;i<=n;i++) {
		read(a[i]);
		a[i]=min(n-i+1,a[i]);
		st[i][0]=i;
	}
	st[n+1][0]=n+1;
	for (int i=2;i<=n+1;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<=15;i++) for (int j=1;j+(1<<i)-1<=n+1;j++)
		st[j][i]=MX(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	for (int i=0;i<=15;i++) for (int j=0;j<=30;j++) f[n+1][i][j]=n+1;
	for (int i=1;i<=n;i++) {
		f[i][0][0]=query(i+1,i+a[i]);
		for (int j=1;j<=30;j++) f[i][0][j]=query(i+1,min(i+a[i]+j,n+1));
	}
	for (int i=1;i<=15;i++) {
		for (int j=1;j<=n;j++) {
			for (int a=0;a<=30;a++) for (int b=0;a+b<=30;b++) {
				f[j][i][a+b]=MX(f[j][i][a+b],f[f[j][i-1][a]][i-1][b]);
			}
		}
	}
	while (m--) {
		int l,r,k; read(l),read(r); read(k);
		int ans=2;
		if (l==r) { puts("0"); continue; }
		if (l+a[l]+k>=r) { puts("1"); continue; }
		for (int i=0;i<=k;i++) A[i]=l;
		for (int x=lg[r-l+1];x>=0;x--) {
			bool flag=1;
			for (int a=0;a<=k&&flag;a++) for (int b=0;a+b<=k;b++) {
				int p=f[A[a]][x][b];
				if (p+::a[p]+k-a-b>=r) { flag=0; break; }
			}
			if (!flag) continue;
			ans+=1<<x;
			for (int a=0;a<=k;a++) B[a]=0;
			for (int a=0;a<=k;a++) for (int b=0;a+b<=k;b++)
				B[a+b]=MX(B[a+b],f[A[a]][x][b]);
			for (int a=0;a<=k;a++) A[a]=B[a];
		}
		printf("%d\n",ans);
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