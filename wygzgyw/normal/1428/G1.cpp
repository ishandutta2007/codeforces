#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e18;
const int maxn=(1e6);
int K,n;
ll F[10],dp[maxn+10],mi[10];
ll tmp,ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(K);
	for (int i=0;i<6;i++) read(F[i]);
	mi[0]=1;
	for (int i=1;i<6;i++) mi[i]=mi[i-1]*10;
	for (int i=0;i<maxn;i++) dp[i]=-INF; dp[0]=0;
	int x,y;
	for (int d=0;d<6;d++) {
		ll now=1,rst=3*(K-1);
		while (rst) {
			now=min(now,rst);
			ll w=now*mi[d]*3,v=now*F[d];
		//	printf("%lld %lld\n",w,v);
			for (int i=maxn-1;i>=w;i--)
				dp[i]=max(dp[i],dp[i-w]+v);
			rst-=now;
			now*=2;
		}
	}
	int q; read(q);
	while (q--) {
		read(n);
		ans=0;
		for (int i=0;i<=n;i++) {
			tmp=0; x=i;
			for (int d=0;d<6;d++) {
				y=x%10;
				if (y%3==0) tmp+=(y/3)*F[d];
				x/=10;
			}
			ans=max(ans,dp[n-i]+tmp);
		}
		printf("%lld\n",ans);
	}
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