#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const double INF=1e17;
const int maxn=(2e5)+10;
int n,m,t[maxn];
double sum[maxn],iv[maxn],pre[maxn];
double f[55][maxn];
void solve(int j,int l,int r,int L,int R) {
	if (l>r) return;
	int mid=(l+r)>>1,pos=0; double tmp;
	for (int i=L;i<=R&&i<mid;i++) if (f[j-1][i]!=INF) {
		tmp=f[j-1][i]+pre[mid]-pre[i]-sum[i]*(iv[mid]-iv[i]);
		if (tmp<f[j][mid]) f[j][mid]=tmp,pos=i;
	}
	solve(j,l,mid-1,L,pos);
	solve(j,mid+1,r,pos,R);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	for (int i=1;i<=n;i++) {
		read(t[i]);
		sum[i]=sum[i-1]+t[i];
		iv[i]=iv[i-1]+1.0/t[i];
		pre[i]=pre[i-1]+sum[i]/t[i];
	}
	for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) f[j][i]=INF;
	f[0][0]=0;
	for (int i=1;i<=m;i++) solve(i,1,n,0,n);
	printf("%.10lf\n",f[m][n]);
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