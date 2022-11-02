#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
const int maxn=310;
const int iv2=(mod+1)/2;
int mi[maxn],ivmi[maxn];
int n,mxdep[maxn],f[maxn][maxn],g[maxn][maxn];
int nf[maxn],ng[maxn],ans;
vector<int> G[maxn];
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
void dfs(int u,int p,int r) {
	mxdep[u]=0;
	f[u][0]=g[u][0]=1;
	for (int v : G[u]) if (v!=p) {
		dfs(v,u,r);
		for (int i=0;i<=max(mxdep[u],mxdep[v]+1);i++) nf[i]=ng[i]=0;
		for (int i=0;i<=mxdep[u];i++) for (int j=0;j<=mxdep[v];j++) {
			update(nf[max(i,j+1)],(ll)f[u][i]*f[v][j]%mod);
			update(ng[min(i,j+1)],(ll)g[u][i]*g[v][j]%mod);
			if (i+j+1<=r) {
				update(ng[j+1],(ll)f[u][i]*g[v][j]%mod);
				update(ng[i],(ll)g[u][i]*f[v][j]%mod);
			}
			else {
				update(nf[i],(ll)f[u][i]*g[v][j]%mod);
				update(nf[j+1],(ll)g[u][i]*f[v][j]%mod);
			}
		}
		mxdep[u]=max(mxdep[u],mxdep[v]+1);
		for (int i=0;i<=mxdep[u];i++)
			f[u][i]=nf[i],g[u][i]=ng[i];
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); int x,y;
	for (int i=1;i<n;i++) read(x),read(y),G[x].push_back(y),G[y].push_back(x);
	for (int i=1;i<=n;i++) {
		dfs(1,0,i);
		for (int j=0;j<=mxdep[1];j++) update(ans,mod-g[1][j]);
	}
	update(ans,mod-1);
	mi[0]=ivmi[0]=1;
	for (int i=1;i<=n;i++) mi[i]=(ll)mi[i-1]*2%mod,ivmi[i]=(ll)ivmi[i-1]*iv2%mod;
	update(ans,(ll)n*mi[n]%mod);
	ans=(ll)ans*ivmi[n]%mod;
	printf("%d\n",ans);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/