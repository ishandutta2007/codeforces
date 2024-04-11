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
int n,k,m,mod;
int dp[110][110][110];
bool vis[110][110][110];
int C[110][110];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int dfs(int n,int dep,int cnt) {
	if (cnt*2>n+1||n<cnt) return 0;
	if (dep>m&&cnt>0) return 0;
	if (dep==m&&cnt>1) return 0;
	if (n==0) return cnt==0;
	if (vis[n][dep][cnt]) return dp[n][dep][cnt];
	vis[n][dep][cnt]=1;
	int lim=cnt-(dep==m);
	for (int a=0;a<n;a++) for (int b=0;b<=lim;b++)
		update(dp[n][dep][cnt],(ll)C[n-1][a]*dfs(a,dep+1,b)%mod*dfs(n-a-1,dep+1,lim-b)%mod);
	return dp[n][dep][cnt];
}
int main() {
	read(n),read(m),read(k),read(mod);
	for (int i=0;i<=n;i++) {
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	printf("%d\n",dfs(n,1,k));
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