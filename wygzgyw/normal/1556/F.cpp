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
int n,a[20],d[20][20],f[1<<14],ans;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
vector<int> b[1<<14];
int G(int s,int t) {
	int res=1;
	for (int x : b[s]) for (int y : b[t]) res=(ll)res*d[x][y]%mod;
	return res;
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (i!=j) d[i][j]=(ll)a[i]*ksm(a[i]+a[j],mod-2)%mod;
	for (int t=1;t<(1<<n);t++) for (int i=1;i<=n;i++) if (t&(1<<(i-1))) b[t].push_back(i);
	for (int t=1;t<(1<<n);t++) {
		f[t]=1;
		for (int s=t;s;s=(s-1)&t) if (s!=t) {
			update(f[t],mod-(ll)f[s]*G(s,t-s)%mod);
		}
		update(ans,(ll)b[t].size()*f[t]%mod*G(t,(1<<n)-1-t)%mod);
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