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
const int maxn=(1<<20)+5;
int C(int n,int k) {
	if ((n&k)==k) return 1; return 0;
}
int ans[maxn],n,b[maxn],k;
int vis[3][maxn],rem[3][maxn];
int query(int n,int v) {
	v=max(v,0);
	if (n<0||v>n) return 0;
	if (vis[k-v][n]) return rem[k-v][n];
	int ans=0;
	for (int i=v;i<=n;i++) ans^=C(n,i);
	vis[k-v][n]=1,rem[k-v][n]=ans;
	return ans;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(k);
	for (int i=1;i<=n;i++) read(b[i]);
	for (int i=1;i<=n;i++) {
		int x=b[i];
		for (int j=i;j<=n;j++) {
			if (j>i) {
				if (b[j]>20) break;
				if ((ll)x*(1LL<<b[j])>=(1<<20)) break;
				x<<=b[j];
			}
			int N=n-1-(j-i),K=k;
			if (i>1) N--,K--;
			if (j<n) N--,K--;
		//	printf("%d %d %d, %d %d\n",i,j,x,N,K);
			if (query(N,K)) ans[x]^=1;
		}
	}
	int fd=-1;
	for (int i=(1<<20)-1;i>=0;i--) if (ans[i]) { fd=i; break; }
	if (fd==-1) { puts("0"); return 0; }
	for (int i=fd;i>=0;i--) printf("%d",ans[i]); puts("");
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