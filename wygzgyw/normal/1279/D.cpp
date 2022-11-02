#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=998244353;
const int maxn=(1e6)+10;
int n,cnt[maxn];
ll ans,tmp,sum;
vector<int> g[maxn];
ll ksm(ll x,ll y) {
	ll res=1;
	while (y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod; y>>=1;
	} return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	int x,y;
	read(n);
	for (int i=1;i<=n;i++) {
		read(x);
		while (x--) {
			read(y); cnt[y]++;
			g[i].push_back(y);
		}
	}
	for (int i=1;i<=n;i++) {
		sum=0;
		for (int j=0;j<g[i].size();j++) sum=(sum+cnt[g[i][j]])%mod;
		tmp=(ll)n*n%mod*g[i].size()%mod;
		ans=(ans+sum*ksm(tmp,mod-2)%mod)%mod;
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