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
const int mod=(1e9)+7;
const int iv2=(mod+1)/2;
const int maxn=(2e6)+10;
int T,n,m,k,jc[maxn],ivjc[maxn],iv[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int C(int x,int y) {
	if (x<y||y<0) return 0;
	return (ll)jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
int mi[maxn];
int main() {
	jc[0]=ivjc[0]=iv[0]=jc[1]=ivjc[1]=iv[1]=1;
	for (int i=2;i<maxn;i++) {
		jc[i]=(ll)jc[i-1]*i%mod;
		iv[i]=(ll)iv[mod%i]*(mod-mod/i)%mod;
		ivjc[i]=(ll)ivjc[i-1]*iv[i]%mod;
	}
	mi[0]=1; for (int i=1;i<maxn;i++) mi[i]=(ll)mi[i-1]*iv2%mod;
	read(T);
	while (T--) {
		read(n),read(m),read(k);
		int ans=0;
		for (int i=1;i<=m;i++) {
			int a=n-i,b=m-i; a-=b;
			int tmp=(ll)C(a+b-1,b)*mi[a+b]%mod*k%mod*i%mod;
			if (a+b-1<0) tmp=(ll)mi[a+b]*k%mod*i%mod;
			update(ans,tmp);
		}
		printf("%d\n",ans);
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