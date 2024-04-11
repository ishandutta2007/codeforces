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
const int maxn=110;
int T,n,a[maxn];
ll ans;
int dp[maxn];
bool vis[300];
int main() {
	read(T);
	while (T--) {
		read(n); ans=0;
		for (int i=1;i<=n;i++) read(a[i]),a[i]=min(a[i],200);
		for (int i=1;i<=n;i++) {
			memset(dp,0,sizeof(dp));
			for (int j=i;j<=n;j++) {
				int mex=0;
				for (int k=j;k>=i;k--) {
					vis[a[k]]=1;
					while (vis[mex]) mex++;
					dp[j]=max(dp[k-1]+mex+1,dp[j]);
				}
				ans+=dp[j];
				for (int k=i;k<=j;k++) vis[a[k]]=0;
			}
		}
		printf("%lld\n",ans);
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