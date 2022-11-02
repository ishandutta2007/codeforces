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
const int maxn=(1e5)+10;
int T,n,a[maxn];
map<int,int> M;
int dp[maxn];
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]),a[i]^=a[i-1];
		int ans=0; M.clear(); M[0]=0;
		for (int i=1;i<=n;i++) {
			dp[i]=dp[i-1]+(a[i]!=a[i-1]);
			if (M.count(a[i])) dp[i]=min(dp[i],dp[M[a[i]]]+i-M[a[i]]-1);
			M[a[i]]=i;
		//	printf("%d %d\n",i,a[i]);
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}