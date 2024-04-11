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
const int maxn=(2e6)+10;
const ll INF=1e18;
int p,q;
int n,m;
char rub[maxn];
char *s[maxn],*now=rub;
int fx[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
int dy[300];
int num(int x,int y) { assert(1<=x&&x<=n&&1<=y&&y<=m); return (x-1)*m+y; }
vector<pair<int,int> > g[300010];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > Q;
ll dis[maxn]; bool vis[maxn];
void link(int x,int y,int z) {
	g[x].push_back(MP(y,z));
}
int main() {
	read(n),read(m);
	read(p),read(q);
	for (int i=1;i<=n;i++) s[i]=now,scanf("%s",s[i]+1),now+=m+3;
	dy['R']=0;
	dy['L']=1;
	dy['U']=2;
	dy['D']=3;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
		for (int k=0;k<4;k++) {
			int x=i+fx[k][0],y=j+fx[k][1];
			if (x<1||x>n||y<1||y>m||s[x][y]=='.'||s[x][y]=='#') continue;
			if ((dy[s[x][y]]^k)==1) {
				link(num(i,j),num(x+fx[k][0],y+fx[k][1]),q);
			} else if (k!=dy[s[x][y]]) {
				int k2=(dy[s[x][y]]^1);
				link(num(i,j),num(x+fx[k2][0],y+fx[k2][1]),p);
			}
		}
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
		int x=num(i,j);
		if (s[i][j]=='.') Q.push(MP(0,x)); else dis[x]=INF;
	}
	while (!Q.empty()) {
		int x=Q.top().second; Q.pop();
		if (vis[x]) continue; vis[x]=1;
		for (auto [y,z] : g[x]) if (dis[y]>dis[x]+z) dis[y]=dis[x]+z,Q.push(MP(dis[y],y));
	}
	ll ans=INF;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
		for (int k=0;k<4;k++) {
			int x=i+fx[k][0],y=j+fx[k][1];
			if (x<1||x>n||y<1||y>m) continue;
			ans=min(ans,dis[num(i,j)]+dis[num(x,y)]);
		}
	}
	if (ans==INF) ans=-1;
	printf("%lld\n",ans);
	
	return 0;
}