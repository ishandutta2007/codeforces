#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e18;
const int maxn=(2e5)+10;
int n;
int s,t,cur[3010],x[3010],y[3010];
int level[3010],tot,lst[3010];
ll flow[maxn],sum,all;
int head[maxn],nxt[maxn];
int to[maxn];
queue<int> q;
void Add_edge(int a,int b,ll c) {
	tot++; nxt[tot]=head[a];
	head[a]=tot; to[tot]=b; flow[tot]=c;
}
void add(int a,int b,ll c) {
	//printf("%d %d %lld\n",a,b,c);
	Add_edge(a,b,c);
	Add_edge(b,a,0);
}
bool bfs() {
	q=queue<int>();
	for (int i=1;i<=t;i++) level[i]=-1,cur[i]=head[i];
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
	read(n);
	for (int i=1;i<=n;i++) read(x[i]);
	for (int i=1;i<=n;i++) read(y[i]);
	tot=1;
	s=n+1,t=n+2;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=x[i];j++) if (x[i]%j==0&&lst[j]) add(i,lst[j],INF);
		if (y[i]>=0) all+=y[i],add(s,i,y[i]);
		else add(i,t,-y[i]);
		lst[x[i]]=i;
	}
	while (bfs()) all-=dfs(s,INF);
	printf("%lld\n",all);
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