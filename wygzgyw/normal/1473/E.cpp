#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e18;
int n,m;
ll dis[200010][4];
bool vis[200010][4];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
int F(int x,int y) {
	return x*4+y;
}
int tot,head[200010],to[400010],nxt[400010],w[400010];
void add(int x,int y,int z) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y; w[tot]=z;
}
void update(int x,int y,ll d) {
	if (dis[x][y]>d) dis[x][y]=d,q.push(make_pair(d,F(x,y)));
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	int x,y,z;
	for (int i=1;i<=m;i++) {
		read(x),read(y),read(z);
		add(x,y,z),add(y,x,z);
	}
	for (int i=1;i<=n;i++) dis[i][0]=dis[i][1]=dis[i][2]=dis[i][3]=INF;
	dis[1][0]=0;
	q.push(make_pair(0LL,F(1,0)));
	int id; ll d;
	while (!q.empty()) {
		id=q.top().second,d=q.top().first; q.pop();
		x=id/4,y=id%4;
		if (vis[x][y]) continue; vis[x][y]=1;
		for (int i=head[x],v;i;i=nxt[i]) {
			v=to[i];
			update(v,y,dis[x][y]+w[i]);
			if (!(y&1)) update(v,y|1,dis[x][y]+2*w[i]);
			if (!(y&2)) update(v,y|2,dis[x][y]);
			if (!(y&3)) update(v,y|3,dis[x][y]+w[i]);
		}
	}
	for (int i=2;i<=n;i++) printf("%lld ",dis[i][3]);
	puts("");
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