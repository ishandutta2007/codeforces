#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
const int INF=0x7f7f7f7f;
int n,m,cnt,ans,rem[410][410];
int dis[410][410],tmp;
queue<int> q;
vector<int> g[410];
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m); int x,y;
	for (int i=1;i<=m;i++) read(x),read(y),g[x].push_back(y),g[y].push_back(x);
	memset(dis,INF,sizeof(dis));
	for (int i=1;i<=n;i++) {
		q.push(i);
		dis[i][i]=0;
		while (!q.empty()) {
			int u=q.front(); q.pop();
			for (int v : g[u]) if (dis[i][v]>dis[i][u]+1) dis[i][v]=dis[i][u]+1,q.push(v);
		}
	}
	for (int x=1;x<=n;x++)
	for (int y=x;y<=n;y++) {
		int cnt=0;
		for (int i=1;i<=n;i++) if (dis[x][i]+dis[y][i]==dis[x][y]) cnt++;
		if (cnt>dis[x][y]+1) continue;
		int ans=1;
		for (int i=1;i<=n;i++) {
			if (dis[x][i]+dis[y][i]!=dis[x][y]) {
				int tmp=0;
				for (int v : g[i])
					if (dis[x][v]==dis[x][i]-1&&dis[y][v]==dis[y][i]-1) tmp++;
				ans=(ll)ans*tmp%mod;
				if (!ans) break;
			}
		}
		rem[x][y]=rem[y][x]=ans;
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) printf("%d ",rem[i][j]);
		puts("");
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