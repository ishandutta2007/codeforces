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
const int maxn=(1e5)+10;
int T,n,ans;
int a[maxn];
int b[maxn];
int main() {
	read(T);
	while (T--) {
		read(n);
		ans=1;
		for (int i=1;i<=n;i++) read(a[i]),b[a[i]]=i;
		int l=b[0],r=b[0];
		for (int i=1;i<n;i++) {
			int x=b[i];
			if (l<=x&&x<=r) {
				ans=(ll)ans*(r-l+1-i)%mod;
			}
			l=min(l,x),r=max(r,x);
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