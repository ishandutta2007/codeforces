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
int n,m;
char s[510];
int a[510][510],d[510][510],ans,tmp;

typedef long long ll;
const ll INF=1LL<<50;
const int maxn=100000;
const int maxm=maxn*10;
namespace Dinic {
int s,t,cur[maxn];
int level[maxn],tot=1;
ll ans,flow[maxm];
int head[maxn],nxt[maxm];
int to[maxm];
queue<int> q;
void Add_edge(int a,int b,ll c) {
	tot++; nxt[tot]=head[a];
	head[a]=tot; to[tot]=b; flow[tot]=c;
}
void add_edge(int a,int b,ll c) {
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
ll solve() {
	ll ans=0; while (bfs()) ans+=dfs(s,INF); return ans;
}
};

int main() {
	read(n),read(m);
	for (int i=1;i<=n;i++) { scanf("%s",s+1); for (int j=1;j<=m;j++) d[i][j]=(s[j]=='B'); }
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) a[i][j]=(d[i][j]^d[i+1][j]^d[i][j+1]^d[i+1][j+1]),ans+=a[i][j];
	int all=ans-a[n][m];
	for (int i=1;i<n;i++) for (int j=1;j<m;j++) {
		if (a[i][j]&&a[i][m]&&a[n][j]) Dinic::add_edge(i,j+n,1);
	}
	Dinic::s=n+m+1,Dinic::t=n+m+2;
	for (int i=1;i<n;i++) Dinic::add_edge(Dinic::s,i,1);
	for (int i=1;i<m;i++) Dinic::add_edge(i+n,Dinic::t,1);
	int cnt=Dinic::solve();
	ans=min(ans,all-3*cnt+2*cnt+(a[n][m]^(cnt&1)));
	if (cnt) cnt--,ans=min(ans,all-3*cnt+2*cnt+(a[n][m]^(cnt&1)));
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