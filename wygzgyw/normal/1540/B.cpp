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
const int maxn=210;
int n,dp[maxn][maxn];
int dep[maxn];
vector<int> g[maxn];
int lca[maxn][maxn],iv[maxn];
vector<int> S[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
void dfs(int u,int p) {
	S[u]={u}; dep[u]=dep[p]+1;
	for (int v : g[u]) if (v!=p) {
		dfs(v,u);
		for (int x : S[v]) {
			for (int y : S[u]) lca[x][y]=lca[y][x]=u;
		}
		for (int x : S[v]) S[u].push_back(x);
	}
}

int main() {
	//freopen("1.txt","r",stdin);
	read(n); int x,y;
	iv[0]=iv[1]=1; for (int i=2;i<=n;i++) iv[i]=(ll)iv[mod%i]*(mod-mod/i)%mod;
	for (int i=0;i<=n;i++) {
		for (int j=0;j<=n;j++) {
			if (!i) dp[i][j]=1;
			else if (!j) dp[i][j]=0;
			else dp[i][j]=(ll)(dp[i-1][j]+dp[i][j-1])*iv[2]%mod;
		}
	}
	for (int i=1;i<n;i++) {
		read(x),read(y);
		g[x].push_back(y); g[y].push_back(x);
	}
	int ans=0;
	for (int rt=1;rt<=n;rt++) {
		dfs(rt,0);
		for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) {
			update(ans,dp[dep[j]-dep[lca[i][j]]][dep[i]-dep[lca[i][j]]]);
		}
	}
	ans=(ll)ans*iv[n]%mod;
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