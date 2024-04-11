#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=998244353;
int n,m,k;
ll S[5010][5010],ans,tmp,jc[5010],iv[5010],ivjc[5010];
ll ksm(ll x,ll y) {
	ll res=1;
	while (y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod; y>>=1;
	} return res;
}
ll C(int x,int y) {
	if (x<y) return 0;
	ll res=1;
	for (int i=x;i>=x-y+1;i--) res=res*i%mod;
	return res*ivjc[y]%mod;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); read(k);
	for (int i=1;i<=k;i++) {
		S[i][1]=S[i][i]=1;
		for (int j=2;j<i;j++)
			S[i][j]=(S[i-1][j-1]+(ll)j*S[i-1][j])%mod;
	}
	jc[0]=iv[0]=ivjc[0]=1;
	jc[1]=iv[1]=ivjc[1]=1;
	for (int i=2;i<=k;i++) {
		jc[i]=jc[i-1]*i%mod;
		iv[i]=(mod-mod/i)*iv[mod%i]%mod;
		ivjc[i]=ivjc[i-1]*iv[i]%mod;
	}
	m=ksm(m,mod-2);
	for (int i=1;i<=k;i++) {
		tmp=S[k][i]*jc[i]%mod*C(n,i)%mod*ksm(m,i)%mod;
		ans=(ans+tmp)%mod;
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