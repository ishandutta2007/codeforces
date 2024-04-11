#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int T,n;
ll ans,a[maxn],b[maxn],c[maxn],dp[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		ans=0;
		read(n);
		for (int i=1;i<=n;i++) read(c[i]);
		for (int i=1;i<=n;i++) read(a[i]);
		for (int i=1;i<=n;i++) read(b[i]);
		dp[1]=0;
		for (int i=2;i<=n;i++) {
			if (a[i]!=b[i]) {
				dp[i]=max(dp[i-1]-abs(a[i]-b[i]),abs(a[i]-b[i]))+c[i]+1;
			} else dp[i]=c[i]+1;
			ans=max(ans,dp[i]);
		}
		printf("%lld\n",ans);
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