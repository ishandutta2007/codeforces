#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=998244353;
const int maxn=(2e5)+10;
int n,k,a[maxn],cnt;
ll ans,tmp,iv[maxn];
ll jc[maxn],ivjc[maxn];
ll ksm(ll x,ll y) {
	ll res=1;
	while (y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod; y>>=1;
	} return res;
}
ll C(int x,int y) {
	if (x<y) return 0;
	return jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
int main() {
	//freopen("1.txt","r",stdin);
	iv[0]=ivjc[0]=jc[0]=1;
	iv[1]=ivjc[1]=jc[1]=1;
	for (int i=2;i<maxn;i++) {
		jc[i]=jc[i-1]*i%mod;
		iv[i]=(mod-mod/i)*iv[mod%i]%mod;
		ivjc[i]=ivjc[i-1]*iv[i]%mod;
	}
	read(n); read(k);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++)
		if (a[i]!=a[i%n+1]) cnt++;
	int j;
	for (int i=0;i<=cnt;i++) {
		tmp=ksm(k-2,i)*C(cnt,i)%mod;
		j=cnt-i;
		if (j&1) tmp*=ksm(2,j-1);
		else tmp*=(ksm(2,j)-C(j,j/2))*iv[2]%mod;
		ans=(ans+tmp%mod+mod)%mod;
	}
	printf("%lld\n",ans*ksm(k,n-cnt)%mod);
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