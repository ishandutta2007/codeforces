#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=(1e9)+7;
const int maxn=(1e6)+10;
int n,fa[maxn];
ll S,s[maxn],s1[maxn],s2[maxn],dp[maxn],tmp,ans;
ll gcd(ll x,ll y) {
	if (!x||!y) return x+y;
	return gcd(y,x%y);
}
void update(ll &x,ll y) {
	x+=y; if (x>=mod) x-=mod;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(s[i]),S+=s[i];
	for (int i=2;i<=n;i++) read(fa[i]);
	for (int i=n;i>=2;i--) s[fa[i]]+=s[i];
	for (int i=1;i<=n;i++) {
		tmp=S/gcd(S,s[i]);
		if (tmp<=n) s1[tmp]++;
	}
	for (int i=1;i<=n;i++)
	for (int j=i;j<=n;j+=i) s2[j]+=s1[i];
	dp[1]=1;
	for (int i=1;i<=n;i++)
		if (s2[i]==i) {
			update(ans,dp[i]);
			for (int j=i*2;j<=n;j+=i) update(dp[j],dp[i]);
		}
	printf("%lld\n",ans);
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