#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e17;
int n,m,q,ans;
ll dis[610][610];
ll ori[610][610],mx[610][610];
vector<pair<int,int> > g[610];
pair<ll,ll> d[610];
int mk[610],ok[610][610];
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {
		if (i!=j) dis[i][j]=ori[i][j]=INF;
		mx[i][j]=-INF;
	}
	int x,y,z;
	for (int i=1;i<=m;i++) {
		read(x),read(y); read(z);
		ori[x][y]=ori[y][x]=dis[x][y]=dis[y][x]=z;
	}
	for (int k=1;k<=n;k++)
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	//for (int i=1;i<=n;i++)
	//for (int j=1;j<=n;j++) if (dis[i][j]!=INF) printf("%d %d %lld\n",i,j,dis[i][j]);
	read(q);
	while (q--) {
		read(x),read(y),read(z);
		g[x].push_back(make_pair(z,y));
		g[y].push_back(make_pair(z,x));
	}
	for (int u=1;u<=n;u++) if ((int)g[u].size()>0) {
		for (pair<int,int> A : g[u])
		for (int b=1;b<=n;b++) if (dis[b][A.second]!=INF) {
			mx[u][b]=max(mx[u][b],A.first-dis[b][A.second]);
		}
		for (int a=1;a<=n;a++) {
			for (int b=1;b<=n;b++) if (ori[a][b]!=INF) {
				if (dis[u][a]+ori[a][b]-mx[u][b]<=0) ok[a][b]=1;
			}
		}
		
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<i;j++)
		if (i!=j&&ori[i][j]!=INF&&ok[i][j]) {
			ans++;
			//printf("%d %d\n",i,j);
		}
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