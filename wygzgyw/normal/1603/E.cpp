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
typedef unsigned long long ull;
typedef long long ll;
const int maxn=210;
int n; ull mod,ans;
void update(ull &x,ull y) { if (x>=mod-y) x+=y-mod; else x+=y; }
ull jc[maxn],ivjc[maxn],iv[maxn];
ull f[maxn][maxn][maxn];
int main() {
	read(n),read(mod);
	jc[0]=iv[0]=ivjc[0]=jc[1]=iv[1]=ivjc[1]=1;
	for (int i=2;i<=n;i++) {
		jc[i]=jc[i-1]*i%mod;
		iv[i]=(mod-mod/i)*iv[mod%i]%mod;
		ivjc[i]=ivjc[i-1]*iv[i]%mod;
	}
	int bd=max(1,n-(int)(sqrt(n*1.0))-4); ans=1;
	for (int a1=bd;a1<=n+1;++a1) {
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++) for (int sum=0;sum<=a1;sum++) f[i][sum][0]=jc[n]*ivjc[n-i]%mod;
		for (int k=1;k<=n+1-a1;++k) {
			for (int i=0;i<n;++i) for (int sum=0;sum<=a1;++sum) {
				int b=min((a1-sum)/k,n-i);
				int L=(k<=1?0:max(0,n+2-a1-k-i));
				for (int cnt=L;cnt<=b;++cnt) {
					f[i][sum][k]+=f[i+cnt][sum+cnt*k][k-1]*ivjc[cnt];
					if (((cnt-L)&7)==0) f[i][sum][k]%=mod;
				}
				f[i][sum][k]%=mod;
			}
			for (int sum=0;sum<=a1;sum++) f[n][sum][k]=jc[n];
		}
		update(ans,f[0][0][n+1-a1]);
	}
	printf("%llu\n",ans);
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