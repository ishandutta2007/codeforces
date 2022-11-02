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
int n,m;
ll jc[maxn],ivjc[maxn],iv[maxn],s1,s2;
ll C(int x,int y) {
	if (x<y||y<0) return 0;
	return jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	jc[0]=iv[0]=ivjc[0]=1;
	jc[1]=iv[1]=ivjc[1]=1;
	for (int i=2;i<maxn;i++) {
		jc[i]=jc[i-1]*i%mod;
		iv[i]=(mod-mod/i)*iv[mod%i]%mod;
		ivjc[i]=ivjc[i-1]*iv[i]%mod;
	}
	for (int i=1;i<=n;i++) {
		s1+=C(n-2,i-1)*(i-1)%mod;
		s1%=mod;
	}
	for (int i=1;i<=m;i++) {
		s2+=C(i-1,n-2);
		s2%=mod;
	}
	printf("%lld\n",s1*s2%mod);
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