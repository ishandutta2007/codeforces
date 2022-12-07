#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ll long long
#define fi first
#define se second
#define PB push_back
#define uint unsigned
using namespace std;
const int N=5005;
int n,a[N],b[N];
int id[N],vis[N];
ll v[N];
priority_queue<pll> Q;
bool cmp(int x,int y){
	return v[x]==v[y]?x>y:v[x]<v[y];
}
bool check(int T){
	for (;!Q.empty();Q.pop());
	For(i,1,2*n) id[i]=i,vis[i]=0;
	For(i,1,2*n) v[i]=b[i];
	sort(id+1,id+2*n+1,cmp);
	For(i,1,2*n){
		Q.push(pll(1ll*T*a[id[i]]+b[id[i]],i));
		if (id[i]<=n) vis[id[Q.top().se]]++;
	}
	For(i,1,2*n) v[i]=1ll*a[i]*T+b[i];
	sort(id+1,id+2*n+1,cmp);
	int cnt=0;
	For(i,1,2*n){
		if (id[i]>n) cnt--;
		cnt+=vis[id[i]];
		if (cnt>0) return 0;
	}
	return 1;
}
struct edge{
	int from,to,next,f,v;
}e[N*50];
int head[N*6],tot=1;
void add(int x,int y,int f,int v){
	e[++tot]=(edge){x,y,head[x],f,v};
	head[x]=tot;
	e[++tot]=(edge){y,x,head[y],0,-v};
	head[y]=tot;
}
int q[N*100],Vis[N*6];
int dis[N*6],from[N*6];
int S,T,flow,cost,times;
bool bfs(){
	For(i,1,T) dis[i]=(1<<30),Vis[i]=0;
	int h=0,t=1;
	q[1]=S; dis[S]=0;
	while (h!=t){
		//if (times==2115) cerr<<h<<' '<<t<<' '<<q[h+1]<<endl;
		int x=q[++h]; Vis[x]=0;
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]>dis[x]+e[i].v&&e[i].f){
				dis[e[i].to]=dis[x]+e[i].v;
				from[e[i].to]=i;
				if (!Vis[e[i].to]){
					Vis[e[i].to]=1;
					q[++t]=e[i].to;
				}
			}
	}
	//cerr<<dis[T]<<' '<<dis[S]<<' '<<clock()<<' '<<t<<' '<<++times<<endl;
	return dis[T]!=(1<<30);
}
void del(){
	flow++;
	cost+=dis[T];
	for (int i=from[T];i;i=from[e[i].from])
		e[i].f--,e[i^1].f++;
}
int getT(int t){
	S=6*n+1; T=S+1;
	For(i,1,n){
		add(S,i+0*n,1,0);
		add(i+0*n,i+1*n,1,1);
		add(i+0*n,i+3*n,1<<20,0);
		add(i+1*n,i+3*n,1<<20,0);
		add(i+2*n,i+4*n,1<<20,0);
		add(i+2*n,i+5*n,1<<20,0);
		add(i+4*n,i+5*n,1,1);
		add(i+5*n,T,1,0);
	}
	For(i,1,2*n) id[i]=i;
	For(i,1,2*n) v[i]=b[i];
	sort(id+1,id+2*n+1,cmp);
	Rep(i,2*n,2){
		add(id[i]+1*n,id[i-1]+1*n,1<<20,0);
		if (v[id[i]]==v[id[i-1]])
			add(id[i-1]+1*n,id[i]+1*n,1<<20,0);
	}
	For(i,1,2*n) v[i]=1ll*a[i]*t+b[i];
	sort(id+1,id+2*n+1,cmp);
	Rep(i,2*n,2){
		add(id[i]+3*n,id[i-1]+3*n,1<<20,0);
		if (v[id[i]]==v[id[i-1]])
			add(id[i-1]+3*n,id[i]+3*n,1<<20,0);
	}
	flow=cost=0;
	for (;bfs();del());
	return cost;
}
int main(){
	scanf("%d",&n);
	For(i,1,2*n) scanf("%d%d",&a[i],&b[i]);
	int l=0,r=1e9,ans=r+1;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	if (ans==1e9+1) puts("-1");
	else printf("%d %d\n",ans,getT(ans));
}