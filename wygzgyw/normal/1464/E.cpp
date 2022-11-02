#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
const int maxn=(1e5)+10;
int n,m,sg[maxn],cnt[1<<17],ans;
vector<int> g[maxn];
bool vis[maxn],mk[maxn];
void dfs(int u) {
	if (vis[u]) return;
	vis[u]=1;
	for (int i=0;i<g[u].size();i++) dfs(g[u][i]);
	for (int i=0;i<=(int)g[u].size()+1;i++) mk[i]=0;
	for (int i=0;i<g[u].size();i++) mk[sg[g[u][i]]]=1;
	for (int i=0;i<=(int)g[u].size()+1;i++)
		if (!mk[i]) { sg[u]=i; break; }
}
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	}
	return res;
}
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m); int x,y;
	for (int i=1;i<=m;i++) {
		read(x),read(y);
		g[x].push_back(y);
	}
	for (int i=1;i<=n;i++) if (!vis[i]) dfs(i);
	for (int i=1;i<=n;i++) cnt[sg[i]]++;
	for (int i=0;i<17;i++)
	for (int j=0;j<(1<<17);j++)
		if (!(j>>i&1)) {
			x=cnt[j],y=cnt[j+(1<<i)];
			cnt[j]=x+y,cnt[j+(1<<i)]=x-y;
		}
	for (int i=0;i<(1<<17);i++) update(ans,(ll)ksm(n-cnt[i]+1,mod-2));
	ans=((ll)ans*(mod-ksm((1<<17),mod-2))+1)%mod;
	printf("%d\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/