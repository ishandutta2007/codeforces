#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,a[N],id[N];

struct edge{
	int to,next,f;
};
namespace Net{
	edge e[N*30];
	int head[N],tot,n,S,T;
	int dis[N],cur[N],q[N];
	void add(int x,int y,int f){
		e[++tot]=(edge){y,head[x],f};
		head[x]=tot;
		e[++tot]=(edge){x,head[y],0};
		head[y]=tot;
	}
	void init(int _n){
		n=_n; tot=1; S=2*n+1; T=S+1;
		memset(head,0,sizeof(int)*(2*n+5));
		for (int i=1;i<=n;i++)
			add(S,i,1),add(i+n,T,1);
	}
	void add(int x,int y){
		add(x,y+n,1);	
	}
	bool bfs(){
		for (int i=1;i<=T;i++)
			dis[i]=-1,cur[i]=head[i];
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
	int dfs(int x,int flow){
		if (x==T) return flow;
		int k,rest=flow;
		for (int &i=cur[x];i&&rest;i=e[i].next)
			if (dis[e[i].to]==dis[x]+1&&e[i].f){
				k=dfs(e[i].to,min(rest,e[i].f));
				e[i].f-=k; e[i^1].f+=k;
				if (!(rest-=k)) break; 
			}
		if (rest) dis[x]=-1;
		return flow-rest;
	}
	int Augpath(){
		int ans=n;
		for (;bfs();ans-=dfs(S,1<<30));
		return ans;
	}
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		id[a[i]]=i;
	Net::init(2*n);
	for (int i=1;i<=n;i++)
		Net::add(i,i+n);
	for (int i=1;i<=n;i++)
		for (int j=2*a[i];j<N;j+=a[i])
			if (id[j]){
				Net::add(id[j],i);
				Net::add(id[j]+n,i+n);
			}
	printf("%d\n",n-Net::Augpath());
	for (int i=1;i<=n;i++)
		id[a[i]]=0;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}