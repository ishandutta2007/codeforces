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
const int maxn=(4e6)+10;
int n,rem[maxn],mod,f[maxn],sum[maxn];
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}

int main() {
	read(n),read(mod);
	sum[1]=f[1]=1;
	for (int j=2;j<=n;j++) {
		int z=j/1;
		update(rem[j],(f[j/z]-f[(j-1)/z]+mod)%mod);
	}
	int now=1;
	for (int i=2;i<=n;i++) {
		f[i]=(now+sum[i-1])%mod;
		sum[i]=(sum[i-1]+f[i])%mod;
		for (int j=i*2;j<=n;j+=i) {
			int z=j/i;
			update(rem[j],(f[j/z]-f[(j-1)/z]+mod)%mod);
		}
		update(now,rem[i+1]);
	}
	printf("%d\n",f[n]);
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