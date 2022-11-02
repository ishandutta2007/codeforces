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
const int mod=998244353;
const int maxn=(1e6)+10;
int T,n,v[maxn],k,ans;
int main() {
	read(T);
	while (T--) {
		read(n),read(k); ans=1;
		for (int i=1;i<=n;i++) read(v[i]);
		for (int i=1;i<=k;i++) ans=(ll)ans*i%mod;
		for (int i=k+1;i<=n;i++) {
			int tmp=v[i-k]+k;
			if (v[i-k]==-1) ans=(ll)ans*i%mod;
			else if (tmp>=i) { ans=0; break; }
			else if (v[i-k]==0) ans=(ll)ans*(k+1)%mod;
		}
		for (int i=n-k+1;i<=n;i++) if (v[i]!=-1&&v[i]!=0) ans=0;
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