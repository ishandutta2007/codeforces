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
const int mod=(1e9)+7;
int jc[maxn],iv[maxn],ivjc[maxn];
void init(){jc[0]=jc[1]=iv[0]=iv[1]=ivjc[0]=ivjc[1]=1;for(int i=2;i<maxn;++i)jc[i]=(ll)jc[i-1]*i%mod,iv[i]=(ll)iv[mod%i]*(mod-mod/i)%mod,ivjc[i]=(ll)ivjc[i-1]*iv[i]%mod;}
inline int C(int n,int m){return n<m||m<0?0:(ll)jc[n]*ivjc[m]%mod*ivjc[n-m]%mod;}
int n,a[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int ans;
int main() {
	read(n); n++; init();
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) if (a[i]) {
		update(ans,C(a[i]+i-1,i));
	}
	printf("%d\n",ans);
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