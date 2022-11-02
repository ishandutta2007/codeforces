#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=(1e9)+7;
const int maxn=5010;
int n,k,q,a[maxn],x,y,ans;
int dp[maxn][maxn],c[maxn];
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(k),read(q); k++;
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) dp[1][i]=1;
	for (int i=2;i<=k;i++) {
		for (int j=1;j<=n;j++) {
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
			if (dp[i][j]>=mod) dp[i][j]-=mod;
		}
	}
	for (int i=1;i<=k;i++) for (int j=1;j<=n;j++) update(c[j],(ll)dp[i][j]*dp[k-i+1][j]%mod);
	for (int i=1;i<=n;i++) update(ans,(ll)a[i]*c[i]%mod);
	while (q--) {
		read(x),read(y);
		y=(y-a[x]+mod)%mod;
		update(ans,(ll)c[x]*y%mod);
		update(a[x],y);
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