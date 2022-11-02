#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1LL<<55;
const int maxn=(5e6)+10;
int n,d[maxn],c[maxn],L,R;
ll dp[maxn];
ll mx[maxn],ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	L=(1e9),R=-(1e9);
	for (int i=1;i<=n;i++) {
		read(d[i]),c[i]=i-d[i];
		L=min(L,c[i]);
		R=max(R,c[i]);
	}
	for (int i=0;i<=R-L;i++) mx[i]=-INF;
	ans=-INF;
	for (int i=1;i<=n;i++) {
		dp[i]=max(0LL,mx[c[i]-L])+d[i];
		mx[c[i]-L]=max(mx[c[i]-L],dp[i]);
		ans=max(ans,dp[i]);
	}
	printf("%lld\n",ans);
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