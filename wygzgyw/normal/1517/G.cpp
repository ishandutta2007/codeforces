#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=2010;
const ll INF=1e18;
int n;
struct node { int x,y; ll z; } d[maxn];
int s,t,cur[maxn];
int level[maxn],tot;
ll ans,flow[maxn*20];
int head[maxn],nxt[maxn*20];
int to[maxn*20];
map<pair<int,int>,int> M;
queue<int> q;
void Add_edge(int a,int b,ll c) {
	tot++; nxt[tot]=head[a];
	head[a]=tot; to[tot]=b; flow[tot]=c;
}
void add_edge(int a,int b,ll c) {
	if (!a||!b) return;
	Add_edge(a,b,c);
	Add_edge(b,a,0);
}
bool bfs() {
	q=queue<int>();
	memset(level,-1,sizeof(level));
	for (int i=1;i<=t;i++) cur[i]=head[i];
	q.push(s);
	level[s]=0;
	while (!q.empty()) {
		int a=q.front(),b; q.pop();
		for (register int i=head[a];i;i=nxt[i]) {
			b=to[i];
			if (flow[i]>0&&level[b]==-1) {
				level[b]=level[a]+1;
				q.push(b);
			}
		}
	}
	return level[t]!=-1;
}
ll dfs(int x,ll rest) {
	if (x==t) return rest;
	ll used=0;
	for (register int i=cur[x];i;i=nxt[i]) {
		cur[x]=i;
		int y=to[i];
		if (flow[i]>0&&level[y]==level[x]+1) {
			ll tflow=dfs(y,min(flow[i],rest-used));
			used+=tflow;
			flow[i]-=tflow;
			flow[i^1]+=tflow;
			if (rest-used==0) break;
		}
	}
	if (!used) level[x]=-1;
	return used;
}
int main() {
//	freopen("1.txt","r",stdin);
	read(n); int x,y; ll z;
	for (int i=1;i<=n;i++) {
		read(x),read(y),read(z);
		M[make_pair(x,y)]=i;
		d[i]=(node){x,y,z};
	}
	s=n*2+1,t=s+1; tot=1;
	for (int i=1;i<=n;i++) {
		x=d[i].x,y=d[i].y,z=d[i].z; ans+=z;
		add_edge(i,i+n,z);
		if ((x+y)&1) {
			if (x&1) add_edge(s,i,INF);
			add_edge(i+n,M[make_pair(x+1,y)],INF);
			add_edge(i+n,M[make_pair(x-1,y)],INF);
		} else {
			if (y&1) add_edge(i+n,t,INF);
			else {
				add_edge(i+n,M[make_pair(x,y+1)],INF);
				add_edge(i+n,M[make_pair(x,y-1)],INF);
			}
		}
	}
	while (bfs()) ans-=dfs(s,INF);
	printf("%lld\n",ans);
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