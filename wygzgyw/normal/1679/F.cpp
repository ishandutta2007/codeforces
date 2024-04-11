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
const int maxn=50010;
const int mod=998244353;
int n,m;
int d[10];
int dp[2][1<<10];
int M[10];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int main() {
	read(n),read(m);
	for (int i=1;i<=m;i++) {
		int x,y; read(x),read(y);
		d[y]|=1<<x;
		M[x]|=1<<y,M[y]|=1<<x;
	}
	dp[0][0]=1;
	for (int i=1;i<=n;i++) {
		memset(dp[i&1],0,sizeof(dp[i&1]));
		for (int t=0;t<(1<<10);t++) if (dp[i&1^1][t]) {
		//	printf("i=%d,t=%d\n",i,t);
			for (int j=0;j<=9;j++) {
				if (t>>j&1) continue;
				int s=(t|d[j]);
			//	printf("j=%d %d\n",j,d[j]);
				s&=M[j];
				update(dp[i&1][s],dp[i&1^1][t]);
			}
		}
	}
	int ans=0;
	for (int i=0;i<(1<<10);i++) update(ans,dp[n&1][i]);
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