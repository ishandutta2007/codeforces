#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e17;
const int maxn=(3e5)+10;
const int maxm=(1e7)+10;
int n,m,s,t,S,T,cur[maxn],ns,nt;
int level[maxn],tot,num[maxn];
ll ans,flow[maxm];
ll mn[maxn],mx[maxn],deg[maxn];
int head[maxn],nxt[maxm];
int to[maxm];
ll s1[maxn],s2[maxn];
struct node { int x,y; } a[maxn];
int x[maxn],y[maxn];
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
	for (int i=0;i<=nt;i++) level[i]=-1,cur[i]=head[i];
	q.push(ns);
	level[ns]=0;
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
	return level[nt]!=-1;
}
ll dfs(int x,ll rest) {
	if (x==nt) return rest;
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
ll dinic() {
	ll res=0;
	while (bfs()) res+=dfs(ns,INF);
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	ll RR,BB;
	read(n),read(m),read(RR),read(BB);
	tot=1;
	for (int i=1;i<=n;i++) {
		read(a[i].x),read(a[i].y);
		x[i]=a[i].x,y[i]=a[i].y;
	}
	sort(x+1,x+n+1),sort(y+1,y+n+1);
	int t1=unique(x+1,x+n+1)-x-1,t2=unique(y+1,y+n+1)-y-1;
	s=0,t=t1+t2+1;
	for (int i=1;i<=n;i++) {
		a[i].x=lower_bound(x+1,x+t1+1,a[i].x)-x;
		a[i].y=lower_bound(y+1,y+t2+1,a[i].y)-y;
		add_edge(a[i].x,a[i].y+t1,1);
		s1[a[i].x]++,s2[a[i].y]++;
		num[i]=tot-1;
	}
    for (int i=1;i<=t1+t2;i++) mn[i]=0,mx[i]=n;
    int op,l,d,A; ll L,R;
    for (int i=1;i<=m;i++) {
    	read(op),read(l),read(d);
    	if (op==1) {
    		A=lower_bound(x+1,x+t1+1,l)-x;
    		if (x[A]!=l||d>=s1[A]) continue;
    		L=(s1[A]-d+1)/2,R=s1[A]-L;
    		if (L>R) { puts("-1"); return 0; }
    		mx[A]=min(mx[A],R),mn[A]=max(mn[A],L);
    	} else {
    		A=lower_bound(y+1,y+t2+1,l)-y;
    		if (y[A]!=l||d>=s2[A]) continue;
    		L=(s2[A]-d+1)/2,R=s2[A]-L;
    		if (L>R) { puts("-1"); return 0; }
    		mx[A+t1]=min(mx[A+t1],R),mn[A+t1]=max(mn[A+t1],L);
    	}
    }
	for (int i=1;i<=t1;i++) {
		deg[s]-=mn[i],deg[i]+=mn[i];
		add_edge(s,i,min(s1[i],mx[i])-mn[i]);
		//printf("%lld %lld\n",mn[i],mx[i]);
	}
	for (int i=t1+1;i<=t1+t2;i++) {
		deg[i]-=mn[i],deg[t]+=mn[i];
		add_edge(i,t,min(s2[i-t1],mx[i])-mn[i]);
		//printf("%lld %lld\n",mn[i],mx[i]);
	}
	int nowtot=tot;
	S=t+1,T=t+2;
	add_edge(t,s,INF);
	ll sum=0;
	for (int i=s;i<=t;i++) {
		//printf(" %d %lld\n",i,deg[i]);
		if (deg[i]<0) add_edge(i,T,-deg[i]);
		else if (deg[i]>0) add_edge(S,i,deg[i]),sum+=deg[i];
	}
	ns=S,nt=T;
	//printf("? %d %lld\n",nowtot,sum);
	if (dinic()!=sum) { puts("-1"); return 0; }
	for (int i=nowtot+1;i<=tot;i++) flow[i]=0;
	ns=s,nt=t;
	dinic();
	sum=0;
	for (int i=1;i<=n;i++)
		if (!flow[num[i]]) sum+=min(BB,RR);
		else sum+=max(BB,RR);
    printf("%lld\n",sum);
    for (int i=1;i<=n;i++) {
    	if (!flow[num[i]]) {
    		if (BB<RR) putchar('b'); else putchar('r');
    	} else if (BB<RR) putchar('r'); else putchar('b');
    }
    puts("");
	return 0;
}