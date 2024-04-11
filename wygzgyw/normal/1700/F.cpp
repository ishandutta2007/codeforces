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
const int maxn=(2e5)+10;
int n;
ll sum[2][maxn];

int main() {
	read(n);
	for (int i=0;i<4;i++) {
		for (int j=1;j<=n;j++) {
			int x; read(x);
			if (x) {
				sum[i&1][j]+=((i&2)?1:-1);
			}
		}
	}
	for (int i=0;i<2;i++) for (int j=1;j<=n;j++) sum[i][j]+=sum[i][j-1];
	if (sum[0][n]+sum[1][n]!=0) { puts("-1"); return 0; }
	ll ans=0;
	int a=0,b=0;
	for (int j=1;j<=n;j++) {
		int x=sum[0][j],y=sum[1][j];
		x+=a,y+=b;
		if (x>0&&y<0) a--,b++,ans++;
		else if (x<0&&y>0) a++,b--,ans++;
		sum[0][j]+=a,sum[1][j]+=b;
	}
	for (int i=0;i<2;i++) for (int j=1;j<=n;j++) ans+=abs(sum[i][j]);
	printf("%lld\n",ans);
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