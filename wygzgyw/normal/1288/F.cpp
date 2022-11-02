#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxm=(1e6)+10;
const int INF=0x7f7f7f7f;
int n1,n2,m,r,b,s,t,S,T,tot,ans;
char s1[210],s2[210];
int id[210][2];
struct node {
	int from,to,flow,cost;
} d[maxm];
int head[410],nxt[maxm];
void add_edge(int a,int b,int c,int c2) {
	//printf("%d %d %d %d\n",a,b,c,c2);
	node e;
	e.from=a; e.to=b;
	e.cost=c2; e.flow=c;
	nxt[++tot]=head[a];
	head[a]=tot; d[tot]=e;
	e.from=b; e.to=a;
	e.cost=-c2; e.flow=0;
	nxt[++tot]=head[b];
	head[b]=tot; d[tot]=e;
}
void add1(int a,int b) {
	add_edge(a,b,INF,0);
	add_edge(S,b,1,0);
	add_edge(a,T,1,0);
}
queue<int> q;
int dis[410],edgeTo[410];
bool vis[410];
bool SPFA() {
	memset(vis,0,sizeof(vis));
	memset(dis,INF,sizeof(dis));
	memset(edgeTo,0,sizeof(edgeTo));
	dis[S]=0; q.push(S); vis[S]=1;
	while (!q.empty()) {
		int x=q.front(); q.pop(); vis[x]=0;
		for (register int i=head[x],y;i;i=nxt[i]) {
			y=d[i].to;
			if (d[i].flow&&dis[x]+d[i].cost<dis[y]) {
				dis[y]=dis[x]+d[i].cost;
				edgeTo[y]=i;
				if (!vis[y]) q.push(y),vis[y]=1;
			}
		}
	}
	return dis[T]!=INF;
}
int mincost() {
	int res=0,flow,x,a,b;
	while (SPFA()) {
		flow=INF;
		for (register int i=edgeTo[T];i;i=edgeTo[d[i].from])
			flow=min(flow,d[i].flow);
        for (register int i=edgeTo[T];i;i=edgeTo[d[i].from])
        	d[i].flow-=flow,d[i^1].flow+=flow;
		res+=dis[T]*flow;
	}
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	tot=1;
	read(n1); read(n2);
	read(m); read(r); read(b);
	s=n1+n2+1,t=s+1;
	S=0,T=t+1;
	scanf("%s %s",s1+1,s2+1);
	int x,y;
	for (int i=1;i<=m;i++) {
		read(x); read(y);
		y+=n1;
		add_edge(x,y,1,r);
		id[i][0]=tot-1;
		add_edge(y,x,1,b);
		id[i][1]=tot-1;
	}
	for (int i=1;i<=n1;i++)
		if (s1[i]=='R') add1(s,i);
		else if (s1[i]=='B') add1(i,t);
		else add_edge(s,i,INF,0),add_edge(i,t,INF,0);
	for (int i=1;i<=n2;i++)
		if (s2[i]=='B') add1(s,i+n1);
		else if (s2[i]=='R') add1(i+n1,t);
		else add_edge(s,i+n1,INF,0),add_edge(i+n1,t,INF,0);
	add_edge(t,s,INF,0);
	ans=mincost();
	for (int i=head[S];i;i=nxt[i]) {
		//printf("%d\n",d[i].flow);
		if (d[i].flow) {
			printf("-1\n"); return 0;
		}
	}
	printf("%d\n",ans);
	for (int i=1;i<=m;i++) {
		if (!d[id[i][0]].flow&&d[id[i][1]].flow) printf("R");
		else if (d[id[i][0]].flow&&!d[id[i][1]].flow) printf("B");
		else printf("U");
	}
	printf("\n");
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