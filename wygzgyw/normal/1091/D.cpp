#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=998244353;
const int maxn=(1e6)+10;
int n,d[10],e[200],tot;
ll jc[maxn],iv[maxn],ivjc[maxn],ans;
ll C(int x,int y) {
	return jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
ll F(ll x) {
	if (x==0) return x+1;
	return x;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	jc[0]=iv[0]=ivjc[0]=1;
	jc[1]=iv[1]=ivjc[1]=1;
	for (int i=2;i<=n;i++)
		jc[i]=jc[i-1]*i%mod,
		iv[i]=mod-iv[mod%i]*(mod/i)%mod,
		ivjc[i]=ivjc[i-1]*iv[i]%mod;
	ans=jc[n];
	for (int i=2;i<n;i++)
		ans+=C(n,i)*F(jc[i]-1)%mod*jc[n-i]%mod,ans%=mod;
	printf("%lld\n",ans);
	return 0;
}