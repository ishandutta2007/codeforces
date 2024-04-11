#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh 
using namespace std;
const int N=10005;
int n,m,k,Q,x[15],y[15];
int head[N],tab[15][N*2],tot=1;
int dis[N],q[N],cur[N];
int co[N],f[N],id[15];
int vis[N],visT;
struct edge{
	int to,next,f;
}e[N*2];
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(){
	int h=0,t=1;
	vis[1]=++visT;
	q[1]=1; dis[1]=0; cur[1]=head[1];
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (vis[e[i].to]!=visT&&e[i].f){
				dis[e[i].to]=dis[x]+1;
				vis[e[i].to]=visT;
				cur[e[i].to]=head[e[i].to];
				if (e[i].to==n) return 1;
				q[++t]=e[i].to;
				
			}
	}
	return 0;
}
int bfss(){
	int h=0,t=1;
	vis[1]=++visT;
	q[1]=1; cur[1]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (vis[e[i].to]!=visT&&e[i].f){
				vis[e[i].to]=visT;
				cur[e[i].to]=i;
				if (e[i].to==n){
					int mn=1<<30;
					for (int j=cur[n];j;j=cur[e[j^1].to])
						mn=min(mn,e[j].f);
					for (int j=cur[n];j;j=cur[e[j^1].to])
						e[j].f-=mn,e[j^1].f+=mn;
					//cerr<<t<<endl;
					return mn;
				}
				q[++t]=e[i].to;
			}
	}
	//cerr<<t<<endl;
	return 0;
}
int dfs(int x,int flow){
	if (x==n) return flow;
	int k,rest=flow;
	for (int &i=cur[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&vis[e[i].to]==visT&&e[i].f){
			k=dfs(e[i].to,min(e[i].f,flow));
			e[i].f-=k; e[i^1].f+=k; rest-=k;
			if (!rest) break;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int times=0,tmpclk=0;
void dfs(int d,int S,int v){
	/*if (clock()>4000){
		cout<<times<<' '<<tmpclk<<endl;
		exit(0);
	}*/
	if (d==k+1){
		co[S>>1]=v;
		return;
	}
	int p=id[d];
	dfs(d+1,S|(1<<p),v);
	//++times;
	//cerr<<times<<endl;
	For(i,1,tot) tab[d][i]=e[i].f;
	int t1=head[x[p]],t2=head[y[p]];
	add(x[p],y[p],25);
	for (int val;val=bfss();v+=val);
	dfs(d+1,S,v);
	head[x[p]]=t1; head[y[p]]=t2; tot-=2;
	For(i,1,tot) e[i].f=tab[d][i];
}
int main(){
	srand(time(NULL));
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&Q);
	For(i,1,k) scanf("%d%d%*d",&x[i],&y[i]);
	For(i,k+1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); //add(y,x,v);
	}
	int inif=0;
	for (;bfs();inif+=dfs(1,1<<20));
	tmpclk=clock();
	For(i,1,k) id[i]=i;
	random_shuffle(id+1,id+k+1);
	dfs(1,0,inif);
	while (Q--){
		For(i,0,k-1) scanf("%d",&f[1<<i]);
		For(i,1,(1<<k)-1) f[i]=f[i-(i&(-i))]+f[i&(-i)];
		int ans=1<<30;
		For(i,0,(1<<k)-1){
			ans=min(ans,co[i]+f[i]);
			//cout<<co[i]<<' '<<f[i]<<endl;
		}
		printf("%d\n",ans);
	}
}