#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
const int maxn=300010;
int n,jc[maxn],ivjc[maxn],iv[maxn],a[maxn],b[maxn],ans;
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
int C(int x,int y) {
	return (ll)jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	jc[0]=ivjc[0]=iv[0]=jc[1]=ivjc[1]=iv[1]=1;
	for (int i=2;i<maxn;i++) {
		jc[i]=(ll)jc[i-1]*i%mod;
		iv[i]=(ll)(mod-mod/i)*iv[mod%i]%mod;
		ivjc[i]=(ll)ivjc[i-1]*iv[i]%mod;
	}
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) read(b[i]);
	sort(a+1,a+n+1),sort(b+1,b+n+1);
	for (int i=1;i<=n;i++) update(ans,abs(a[i]-b[n-i+1])%mod);
	printf("%d\n",(ll)ans*C(n*2,n)%mod);
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