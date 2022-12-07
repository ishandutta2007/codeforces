#include<bits/stdc++.h>
using namespace std;

const int N=1005;
int n,x[N],y[N],p[N];

struct edge{
	int to,next;
	long long f;
}e[N*50];
int head[N*2],tot=1;
int dis[N*2],q[N*2],S,T;
map<pair<int,int>,int> mp;
long long ans;

void add(int x,int y,long long f){
	e[++tot]=(edge){y,head[x],f};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;	
}
bool bfs(){
	for (int i=1;i<=T;i++)
		dis[i]=-1;
	int h=0,t=1;
	q[1]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]==-1&&e[i].f){
				dis[e[i].to]=dis[x]+1;
				q[++t]=e[i].to;
				if (e[i].to==T) return 1;
			}
	}
	return 0;
}
long long dfs(int x,long long flow){
	if (x==T) return flow;
	long long rest=flow;
	for (int i=head[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			long long k=dfs(e[i].to,min(rest,e[i].f));
			e[i].f-=k; e[i^1].f+=k; rest-=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&y[i],&x[i],&p[i]);
		mp[pair<int,int>(x[i],y[i])]=i;
		ans+=p[i]; add(i,i+n,p[i]);
	}
	S=2*n+1; T=2*n+2;
	for (int i=1;i<=n;i++)	
		if (y[i]%2!=0&&x[i]%2==0){
			int p;
			p=mp[pair<int,int>(x[i],y[i]-1)];
			if (p) add(i+n,p,1ll<<50);
			p=mp[pair<int,int>(x[i],y[i]+1)];
			if (p) add(i+n,p,1ll<<50);
			add(S,i,1ll<<50);
		}
	for (int i=1;i<=n;i++)	
		if (y[i]%2==0&&x[i]%2==0){
			int p;
			p=mp[pair<int,int>(x[i]-1,y[i])];
			if (p) add(i+n,p,1ll<<50);
			p=mp[pair<int,int>(x[i]+1,y[i])];
			if (p) add(i+n,p,1ll<<50);
		}
	for (int i=1;i<=n;i++)	
		if (y[i]%2==0&&x[i]%2!=0){
			int p;
			p=mp[pair<int,int>(x[i],y[i]-1)];
			if (p) add(i+n,p,1ll<<50);
			p=mp[pair<int,int>(x[i],y[i]+1)];
			if (p) add(i+n,p,1ll<<50);
		}
	for (int i=1;i<=n;i++)	
		if (y[i]%2!=0&&x[i]%2!=0)
			add(i+n,T,1ll<<50);
	for (;bfs();ans-=dfs(S,1ll<<50));
	cout<<ans<<endl;
}