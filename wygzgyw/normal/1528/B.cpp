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
typedef long long ll;
const int mod=998244353;
const int maxn=(1e6)+10;
int N,n,f[maxn];
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
int s[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	f[0]=f[1]=1;
	s[0]=1,s[1]=2;
	read(N);
	for (int n=0;n<=N;n++) {
		if (n>=2) {
			update(f[n],f[n-1]);
			update(f[n],s[n-2]);
			s[n]=(s[n-1]+f[n])%mod;
		}
		if (n) {
			for (int j=n*2;j<=N;j+=n) update(f[j],1);
		}
	}
	printf("%d\n",f[N]);
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