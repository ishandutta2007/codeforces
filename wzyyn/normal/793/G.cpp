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
const int M=1000005;
struct edge{
	int to,next,f;
}e[M*5];
vector<pii> v1[N],v2[N];
int n,Q,rt,head[M],tot=1,nd,S,T;
int ls[M],rs[M],q[M],dis[M],ans;
void add(int,int,int);
void build(int &k,int l,int r){
	if (l==r) return k=n+l,void(0);
	int mid=(l+r)/2;
	k=++nd;
	build(ls[k],l,mid);
	build(rs[k],mid+1,r);
	add(k,ls[k],1<<30);
	add(k,rs[k],1<<30);
}
void insert(int &nk,int k,int p,int l,int r,int x,int y){
	if (x<=l&&r<=y) return nk=p,void(0);
	int mid=(l+r)/2;
	nk=++nd; ls[nk]=ls[k]; rs[nk]=rs[k];
	if (x<=mid) insert(ls[nk],ls[k],ls[p],l,mid,x,y);
	if (y>mid) insert(rs[nk],rs[k],rs[p],mid+1,r,x,y);
	add(nk,ls[nk],1<<30);
	add(nk,rs[nk],1<<30);
}

void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot; 
}
bool bfs(){
	For(i,1,nd) dis[i]=-1;
	int h=0,t=1; q[1]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]==-1&&e[i].f){
				dis[e[i].to]=dis[x]+1;
				if (e[i].to==T) return 1;
				q[++t]=e[i].to;
			}
	}
	return 0;
}
int dfs(int x,int flow){
	if (x==T) return flow;
	int k,rest=flow;
	for (int i=head[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,min(rest,e[i].f));
			e[i].f-=k; e[i^1].f+=k; rest-=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	nd=2*n; S=++nd; T=++nd;
	For(i,1,n) add(S,i,1),add(i+n,T,1);
	build(rt,1,n);
	scanf("%d",&Q);
	For(i,1,Q){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		v1[x1].PB(pii(y1,y2));
		v2[x2+1].PB(pii(y1,y2)); 
	}
	int ini=rt;
	For(i,1,n){
		for (auto j:v2[i]) insert(rt,rt,ini,1,n,j.fi,j.se);
		for (auto j:v1[i]) insert(rt,rt,0,1,n,j.fi,j.se);
		add(i,rt,1);
	}
	int ans=0;
	for (;bfs();ans+=dfs(S,1<<30));
	printf("%d\n",ans);
}