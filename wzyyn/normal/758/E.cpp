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
const int N=200005;
struct edge{
	int to,next,w,v;
}e[N*2];
int head[N],ord[N],n,tot;
int fa[N],faid[N],dif[N];
ll rem[N],lo[N],hi[N];
void GG(){
	puts("-1");
	exit(0);
}
void add(int x,int y,int a,int b){
	e[++tot]=(edge){y,head[x],a,b};
	head[x]=tot;
}
void dfs1(int x){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			faid[e[i].to]=i;
			dfs1(e[i].to);
			if (e[i].v<lo[e[i].to]) GG();
			hi[e[i].to]=min(hi[e[i].to],1ll*e[i].v);
			dif[e[i].to]=min(e[i].w-1ll,e[i].v-lo[e[i].to]);
			lo[x]+=lo[e[i].to]+e[i].w-dif[e[i].to];
			hi[x]+=hi[e[i].to]+e[i].w;
		}
}
void dfs2(int x){
	//cout<<x<<' '<<rem[x]<<' '<<lo[x]<<' '<<hi[x]<<endl;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			rem[e[i].to]=lo[e[i].to];
			rem[x]-=lo[e[i].to]+e[i].w-dif[e[i].to];
		}
	assert(rem[x]>=0);
	//cout<<x<<' '<<rem[x]<<' '<<lo[x]<<' '<<hi[x]<<endl;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			ll tmp,up=min(hi[e[i].to],1ll*e[i].v-dif[e[i].to]);
			tmp=min(rem[x],up-lo[e[i].to]);
			rem[e[i].to]+=tmp; rem[x]-=tmp;
			tmp=min(rem[x]/2,hi[e[i].to]-up);
			dif[e[i].to]-=tmp; rem[e[i].to]+=tmp; rem[x]-=tmp*2;
			tmp=min(rem[x],1ll*dif[e[i].to]);
			dif[e[i].to]-=tmp; rem[x]-=tmp;
			dfs2(e[i].to);
		}	
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y,a,b;
		scanf("%d%d%d%d",&x,&y,&a,&b);
		add(x,y,a,b); add(y,x,a,b);
		ord[i]=y;
	}
	dfs1(1);
	rem[1]=hi[1];
	dfs2(1);
	printf("%d\n",n);
	For(i,1,n-1){
		int y=ord[i],x=fa[y];
		printf("%d %d %d %d\n",x,y,e[faid[y]].w-dif[y],e[faid[y]].v-dif[y]);
	}
}