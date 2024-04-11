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
const ull mod=998244353;
const int maxn=(1e7)+10;
int T,n,k,x;
ull ans,mi[maxn],suf[maxn];
void update(ull &x,ull y) { if (x>=mod-y) x+=y-mod; else x+=y; }
ull ksm(ull x,ull y) {
	ull res=1;
	while (y) {
		if (y&1) res=res*x%mod; x=x*x%mod; y>>=1;
	} return res;
}
int main() {
	mi[0]=1; for (int i=1;i<maxn;i++) mi[i]=mi[i-1]*2%mod;
	suf[0]=1; for (int i=1;i<maxn;i++) suf[i]=suf[i-1]*(mi[i]-1)%mod;
	suf[maxn-1]=ksm(suf[maxn-1],mod-2);
	for (int i=maxn-2;i>=1;i--) suf[i]=suf[i+1]*(mi[i+1]-1)%mod;
	read(T);
	while (T--) {
		read(n),read(k),read(x);
		if (x==0) {
			if (n>k) { puts("0"); continue; }
			ans=1;
			for (int i=0;i<n;i++) ans=ans*(mi[k]-mi[i]+mod)%mod; printf("%llu\n",ans); continue;
		}
		ans=0;
		int qn=ksm(2,n);
		ull tmp=1,fz=1,iv2=(mod+1)/2;
		for (int i=1;i<k;i++) {
			tmp=tmp*(mi[k]-mi[i-1]+mod)%mod;
			fz=fz*(qn-1)%mod,qn=qn*iv2%mod;
			update(ans,tmp*fz%mod*suf[i]%mod*(mi[k]-mi[i]+mod)%mod);
		}
		printf("%llu\n",(ans*ksm(mi[k]-1,mod-2)%mod+1)%mod);
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