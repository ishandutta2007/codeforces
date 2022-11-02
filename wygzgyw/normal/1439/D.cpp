#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int n,m,mod,dp1[510],dp2[510],dp3[510][510],dp4[510][510];
int C[510][510];
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m),read(mod);
	for (int i=0;i<=500;i++) {
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	dp1[0]=1;
	for (int i=1;i<=500;i++) {
		for (int j=1;j<=i;j++) {
			update(dp1[i],(ll)dp1[j-1]*dp1[i-j]%mod*C[i-1][j-1]%mod);
		}
		dp1[i]=(ll)dp1[i]*(i+1)%mod;
		for (int j=1;j<=i;j++) {
			update(dp2[i],(ll)(i+1)*C[i-1][j-1]%mod*((ll)dp1[j-1]*dp2[i-j]%mod+(ll)dp2[j-1]*dp1[i-j]%mod)%mod);
			update(dp2[i],(ll)C[i-1][j-1]*dp1[j-1]%mod*dp1[i-j]%mod*(j*(j-1)/2+(i-j)*(i-j+1)/2)%mod);
		}
	}
	//for (int i=1;i<=n;i++) printf("%lld ",dp2[i]); printf("\n");
	dp3[0][0]=1;
	for (int n=1;n<=500;n++) {
		for (int m=0;m<n;m++) {
			dp3[n][m]=dp3[n-1][m];
			dp4[n][m]=dp4[n-1][m];
			for (int i=1;i<=m;i++) {
				update(dp3[n][m],(ll)dp3[n-i-1][m-i]*dp1[i]%mod*C[m][i]%mod);
				update(dp4[n][m],(ll)dp3[n-i-1][m-i]*dp2[i]%mod*C[m][i]%mod);
				update(dp4[n][m],(ll)dp4[n-i-1][m-i]*dp1[i]%mod*C[m][i]%mod);
			}
		}
		dp3[n][n]=dp1[n],dp4[n][n]=dp2[n];
	}
	printf("%d\n",dp4[n][m]);
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