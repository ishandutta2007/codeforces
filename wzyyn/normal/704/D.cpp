#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=100005;
struct edge{
	int to,next,f;
}e[N*10];
int x[N],y[N],dx[N],dy[N];
int cntx[N],cnty[N],lx[N],ly[N];
int n,m,R,B,sum,ans,tot=1;
int head[N*2],q[N*2],id[N];
int dis[N*2],cur[N*2];
int out[N*2],in[N*2];
void add(int x,int y,int f){
	//printf("EDG %d %d %d\n",x,y,f);
	e[++tot]=(edge){y,head[x],f};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool BFS(int S,int T){
	For(i,1,T) dis[i]=-1;
	int h=0,t=1; q[1]=S; dis[S]=0;
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
int dfs(int x,int flow,int T){
	if (x==T) return flow;
	int k,rest=flow;
	for (int &i=cur[x];i;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,min(rest,e[i].f),T);
			e[i].f-=k; e[i^1].f+=k; rest-=k;
			if (!rest) break;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&R,&B);
	For(i,1,n) scanf("%d%d",&x[i],&y[i]);
	For(i,1,n) dx[i]=x[i],dy[i]=y[i];
	sort(dx+1,dx+n+1);
	sort(dy+1,dy+n+1);
	*dx=unique(dx+1,dx+n+1)-dx-1;
	*dy=unique(dy+1,dy+n+1)-dy-1;
	int S=(*dx)+(*dy)+1,T=S+1,SS=T+1,TT=SS+1;
	For(i,1,n){
		x[i]=lower_bound(dx+1,dx+*dx+1,x[i])-dx;
		y[i]=lower_bound(dy+1,dy+*dy+1,y[i])-dy;
		++cntx[x[i]]; ++cnty[y[i]]; id[i]=tot+1;
		add(x[i],(*dx)+y[i],1); 
	}
	For(i,1,*dx) lx[i]=1e9;
	For(i,1,*dy) ly[i]=1e9;
	For(i,1,m){
		int tp,x,l,d;
		scanf("%d%d%d",&tp,&l,&d);
		if (tp==1){
			x=lower_bound(dx+1,dx+*dx+1,l)-dx;
			if (dx[x]==l) lx[x]=min(lx[x],d);
		}
		else{
			x=lower_bound(dy+1,dy+*dy+1,l)-dy;
			if (dy[x]==l) ly[x]=min(ly[x],d);
		}
	}
	For(i,1,*dx){
		int L=max(0,(cntx[i]-lx[i]+1)/2);
		int R=min(cntx[i],(cntx[i]+lx[i])/2); 
		if (L>R) return puts("-1"),0;
		out[S]+=L; in[i]+=L;
		add(S,i,R-L);
	}
	For(i,1,*dy){
		int L=max(0,(cnty[i]-ly[i]+1)/2);
		int R=min(cnty[i],(cnty[i]+ly[i])/2);
		if (L>R) return puts("-1"),0;
		out[i+(*dx)]+=L; in[T]+=L;
		add(i+(*dx),T,R-L);
	}
	For(i,1,T)
		if (in[i]>out[i]){
			sum+=in[i]-out[i];
			add(SS,i,in[i]-out[i]);
		}
		else
			add(i,TT,out[i]-in[i]);
	//printf("%d\n",sum);
	add(T,S,1<<30);
	for (;BFS(SS,TT);){
		For(i,1,TT) cur[i]=head[i];
		sum-=dfs(SS,1<<30,TT);
	}
	//printf("%d\n",sum);
	if (sum)
		return puts("-1"),0;
	for (;BFS(S,T);){
		For(i,1,T) cur[i]=head[i];
		ans+=dfs(S,1<<30,T);
	}
	bool rev=(R>B);
	if (rev) swap(R,B);
	printf("%lld\n",1ll*R*ans+1ll*B*(n-ans));
	For(i,1,n) putchar(e[id[i]].f^rev?'b':'r');
}