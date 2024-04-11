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
const int mod=(1e9)+7;
const int maxn=8010;
int p[5],R,d,id[110][110];
int mat[maxn][maxn],N; pair<int,int> BK[maxn];
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int fx[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
void Guass() {
	for (int i=1;i<=N;++i) {
		assert(mat[i][i]);
		int tmp=ksm(mat[i][i],mod-2);
		for (int j=i;j<=min(N,i+d);++j) mat[i][j]=(ll)mat[i][j]*tmp%mod;
		mat[i][N+1]=(ll)mat[i][N+1]*tmp%mod;
		for (int j=i+1;j<=min(N,i+d);++j) if (mat[j][i]) {
			tmp=mat[j][i];
			for (int k=i;k<=min(N,i+d);++k) update(mat[j][k],mod-(ll)tmp*mat[i][k]%mod);
			update(mat[j][N+1],mod-(ll)tmp*mat[i][N+1]%mod);
		}
	}
}
int ans[maxn],res;
int main() {
	read(R); int sum=0;
	for (int i=0;i<=3;i++) read(p[i]),update(sum,p[i]);
	sum=ksm(sum,mod-2); for (int i=0;i<=3;i++) p[i]=(ll)p[i]*sum%mod;
	for (int i=-R;i<=R;i++) for (int j=-R;j<=R;j++) if (i*i+j*j<=R*R)
		id[i+R][j+R]=++N,BK[N]=MP(i,j);
	d=2*R+1;
	for (int i=1;i<=N;i++) {
		int x=BK[i].first,y=BK[i].second;
		for (int j=0;j<4;j++) {
			int a=x+fx[j][0],b=y+fx[j][1];
			if (a*a+b*b<=R*R) mat[i][id[a+R][b+R]]=p[j];
		}
		mat[i][i]=mat[i][N+1]=mod-1;
	}
	Guass();
	for (int i=N;i>=1;i--) {
		ans[i]=mat[i][N+1];
		for (int j=i+1;j<=N;j++) update(ans[i],mod-(ll)mat[i][j]*ans[j]%mod);
	}
	printf("%d\n",ans[id[R][R]]);
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