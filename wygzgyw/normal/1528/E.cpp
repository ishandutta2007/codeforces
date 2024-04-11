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
typedef long long ll;
const int mod=998244353;
const int maxn=(1e6)+10;
int n,dp[maxn],s[maxn],dp2[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int iv2,iv6,ans;
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); if (n==1) { puts("5"); return 0; }
	iv2=(mod+1)/2,iv6=ksm(6,mod-2);
	dp[0]=s[0]=1;
	for (int i=1;i<=n;i++) {
		dp[i]=dp[i-1];
		update(dp[i],(ll)dp[i-1]*s[i-2]%mod);
		update(dp[i],(ll)dp[i-1]*(dp[i-1]+1)%mod*iv2%mod);
		s[i]=(s[i-1]+dp[i])%mod;
		dp2[i]=(dp[i]-dp[i-1]+mod)%mod;
	}
	ans=dp[n];
	update(ans,(ll)dp[n-1]*s[n-2]%mod*(s[n-2]+1)%mod*iv2%mod);
	update(ans,(ll)dp[n-1]*(dp[n-1]+1)%mod*iv2%mod*s[n-2]%mod);
	update(ans,(ll)dp[n-1]*(dp[n-1]+1)%mod*(dp[n-1]+2)%mod*iv6%mod);
	ans=(ll)ans*2%mod-1;
	for (int i=1;i<n-1;i++) update(ans,(ll)dp2[n-1-i]*(dp[i]-1)%mod);
	printf("%d\n",ans);
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