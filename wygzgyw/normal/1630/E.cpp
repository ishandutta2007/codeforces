// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
typedef long long ll;
const int maxn=(1e6)+10;
const int mod=998244353;
int T,n,a[maxn];
int cnt[maxn];
int s1[maxn],s2[maxn];
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int jc[maxn],ivjc[maxn],iv[maxn];
int vis[maxn],tim,rem[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int main() {
	jc[0]=iv[0]=ivjc[0]=jc[1]=iv[1]=ivjc[1]=1;
	for (int i=2;i<maxn;i++) {
		jc[i]=(ll)jc[i-1]*i%mod;
		iv[i]=(ll)iv[mod%i]*(mod-mod/i)%mod;
		ivjc[i]=(ll)ivjc[i-1]*iv[i]%mod;
	}
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) cnt[i]=0;
		int G=0,flag=1,Sum=0,Sq=0;
		for (int i=1;i<=n;i++) read(a[i]),cnt[a[i]]++,flag&=(a[i]==a[1]);
		for (int i=1;i<=n;i++) G=__gcd(G,cnt[i]),update(Sum,cnt[i]),update(Sq,(ll)cnt[i]*cnt[i]%mod);
		if (flag) { puts("1"); continue; }
		int S1=0,S2=0; tim++;
		for (int i=1;i<=n;i++) {
			int g=__gcd(n,i); g=n/g;
			if (G%g==0) {
				if (vis[g]==tim) s1[i]=rem[g];
				else {
					s1[i]=jc[n/g];
					for (int j=1;j<=n;j++) s1[i]=(ll)s1[i]*ivjc[cnt[j]/g]%mod;
					vis[g]=tim,rem[g]=s1[i];
				}
				update(S1,s1[i]);
				int sum=(ll)Sum*iv[g]%mod,sq=(ll)Sq*iv[g]%mod*iv[g]%mod;
				s2[i]=(ll)s1[i]*iv[n/g]%mod*iv[n/g-1]%mod*((ll)sum*sum%mod-sq+mod)%mod*n%mod;
				update(S2,s2[i]);
			//printf("G=%d,g=%d s1=%d %lld s2=%d\n",G,g,s1[i],((ll)sum*sum%mod-sq+mod)%mod,s2[i]);
			}
		}
		printf("%lld\n",(ll)S2*ksm(S1,mod-2)%mod);
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