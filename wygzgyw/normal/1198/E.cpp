#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=12000;
const int INF=1<<30;
int n,m,s,t,ans,cur[maxn];
int level[maxn],cnt,d[maxn];
struct node {
	int from,to,ca,flow,fid,tid;
}; vector<node> g[maxn];
queue<int> q;
int get_left(int a,node e) {
	if (a==e.from)
		return e.ca-e.flow;
	return e.flow;
}
int get_other(int a,node e) {
	if (a==e.from)
		return e.to;
	return e.from;
}
void add_edge(int a,int b,int c) {
	node e;
	e.from=a; e.to=b;
	e.fid=g[a].size();
	e.tid=g[b].size();
	e.ca=c; e.flow=0;
	g[a].push_back(e);
	g[b].push_back(e);
}
void add_flow(int a,node &e,int f) {
	if (a==e.from)
		e.flow+=f;
	else e.flow-=f;
}
bool bfs() {
	q=queue<int>();
	memset(level,-1,sizeof(level));
	memset(cur,0,sizeof(cur));
	q.push(s);
	level[s]=0;
	while (!q.empty()) {
		int a=q.front();
		q.pop();
		for (register int i=0;i<g[a].size();++i) {
			node e=g[a][i];
			int b=get_other(a,e);
			if (get_left(a,e)>0&&level[b]==-1) {
				level[b]=level[a]+1;
				q.push(b);
			}
		}
	}
	return level[t]!=-1;
}
int dfs(int x,int rest) {
	if (x==t) return rest;
	int used=0;
	for (register int i=cur[x];i<g[x].size();++i) {
		cur[x]=i;
		node e=g[x][i];
		int y=get_other(x,e);
		if (get_left(x,e)>0&&level[y]==level[x]+1) {
			int tflow=dfs(y,min(get_left(x,e),rest-used));
			used+=tflow;
			add_flow(x,g[e.from][e.fid],tflow);
			add_flow(x,g[e.to][e.tid],tflow);
			if (rest-used==0) break;
		}
	}
	if (!used) level[x]=-1;
	return used;
}
void F(int &x) {
	x=lower_bound(d+1,d+cnt+1,x)-d;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	int x1[maxn],y1[maxn],x2[maxn],y2[maxn];
	for (int i=1;i<=m;i++) {
		read(x1[i]); read(y1[i]); read(x2[i]); read(y2[i]);
		x2[i]++; y2[i]++;
		d[++cnt]=x1[i]; d[++cnt]=y1[i];
		d[++cnt]=x2[i]; d[++cnt]=y2[i];
	}
	sort(d+1,d+cnt+1);
	cnt=unique(d+1,d+cnt+1)-d-1;
	for (int i=1;i<=m;i++) {
		F(x1[i]),F(y1[i]),F(x2[i]),F(y2[i]);
		for (int j=x1[i];j<x2[i];j++)
		for (int k=y1[i];k<y2[i];k++)
			add_edge(j,k+cnt,INF);
	}
	s=cnt*2+1,t=s+1;
	for (int i=1;i<cnt;i++)
		add_edge(s,i,d[i+1]-d[i]),
		add_edge(i+cnt,t,d[i+1]-d[i]);
	while (bfs())
		ans+=dfs(s,INF);
	printf("%d\n",ans);
	return 0;
}