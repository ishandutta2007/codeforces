#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=1010;
int T,n,dp[maxn][4][4],ans;
char s[maxn],A[4],B[4];
void update(int &x,int y) {
	if (x>y) x=y;
}
int main() {
	//freopen("1.txt","r",stdin);
	int a,b;
	read(T);
	A[1]='1',A[2]='0',A[3]='1';
	B[1]='0',B[2]='1',B[3]='0';
	while (T--) {
		scanf("%s",s+1);
		n=strlen(s+1);
		for (int i=0;i<=n;i++)
		for (int j=0;j<=2;j++)
		for (int k=0;k<=2;k++) dp[i][j][k]=n+1;
		dp[0][0][0]=0;
		for (int i=0;i<n;i++)
		for (int j=0;j<=2;j++)
		for (int k=0;k<=2;k++) {
			for (int l='0';l<='1';l++) {
				a=j,b=k;
				if (l==A[a+1]) a++;
				if (l==B[b+1]) b++;
				if (a>2||b>2) continue;
				update(dp[i+1][a][b],dp[i][j][k]+(s[i+1]!=l));
			}
		}
		ans=n+1;
		for (int j=0;j<=2;j++)
		for (int k=0;k<=2;k++) update(ans,dp[n][j][k]);
		printf("%d\n",ans);
	}
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