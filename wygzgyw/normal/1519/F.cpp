#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=16000;
const int INF=0x7f7f7f7f;
int n,m,a[7],b[7],mi[7],c[7];
int dp[maxn],f[7][maxn][7],ans;
void update(int &x,int y) {
	if (x>y) x=y;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	mi[0]=mi[1]=1;
	for (int i=1;i<=m;i++) read(b[i]),mi[i+1]=mi[i]*(b[i]+1);
	memset(dp,INF,sizeof(dp));
	int x=0;
	for (int i=1;i<=m;i++) x+=mi[i]*b[i];
	dp[x]=0;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) read(c[j]);
		memset(f,INF,sizeof(f));
		for (int t=0;t<mi[m+1];t++) f[0][t][0]=dp[t];
		
		for (int j=1;j<=m;j++)
		for (int t=0;t<mi[m+1];t++) {
			
			for (int k=0;k<=a[i];k++) if (f[j-1][t][k]!=INF) {
				int bd=min(a[i]-k,(t/mi[j])%(b[j]+1));
				for (int l=0;l<=bd;l++)
					update(f[j][t-mi[j]*l][k+l],f[j-1][t][k]+(l>0)*c[j]);
			}
		}
		for (int t=0;t<mi[m+1];t++) dp[t]=f[m][t][a[i]];
		
	}
	ans=INF;
	for (int t=0;t<mi[m+1];t++) update(ans,dp[t]);
	if (ans==INF) ans=-1;
	printf("%d\n",ans);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/