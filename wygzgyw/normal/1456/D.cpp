#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=0x7f7f7f7f;
int n;
ll g[5010];
ll t[5010],x[5010];
bool f[5010][5010];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(t[i]),read(x[i]);
	memset(g,INF,sizeof(g));
	g[0]=0;
	for (int i=0;i<n;i++) {
		if (g[i]<=t[i]) {
			g[i+1]=min(g[i+1],max(g[i]+abs(x[i]-x[i+1]),t[i]));
			for (int j=i+2;j<=n;j++)
				f[i+1][j]|=(max(g[i]+abs(x[i]-x[j]),t[i])+abs(x[j]-x[i+1])<=t[i+1]);
		}
		for (int j=i+2;j<=n;j++)
			f[i+1][j]|=(f[i][j]&&t[i]+abs(x[i]-x[i+1])<=t[i+1]);
		if (f[i][i+1]&&i+2<=n) {
			g[i+2]=min(g[i+2],max(t[i]+abs(x[i]-x[i+2]),t[i+1]));
			for (int k=i+3;k<=n;k++)
				f[i+2][k]|=(max(t[i]+abs(x[i]-x[k]),t[i+1])+abs(x[k]-x[i+2])<=t[i+2]);
		}
	}
	if (g[n]<=t[n]||f[n-1][n]) printf("YES\n");
	else printf("NO\n");
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/