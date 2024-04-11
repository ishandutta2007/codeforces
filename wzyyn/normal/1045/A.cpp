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
const int N=15005;
struct edge{
	int to,next,f;
}e[N*100];
int head[N],tot=1;
int n,m,S,T,nd,ls[N],rs[N],rt;
int dis[N],q[N],dep[N],sum[N];
int mat[N],id[N],tp[N];
vector<int> vec[N];
void add(int x,int y,int v){
	//cout<<"EDG "<<x<<' '<<y<<' '<<v<<endl;
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(){
	For(i,1,nd) dis[i]=-1;
	int h=0,t=1;
	q[1]=S; dis[S]=0;
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
int build_tr(int l,int r,int d){
	if (l==r) return l;
	int mid=(l+r)/2,x=++nd;
	add(x,ls[x]=build_tr(l,mid,d-1),1<<30);
	add(x,rs[x]=build_tr(mid+1,r,d-1),1<<30);
	dep[x]=d; return x;
}
void add_e(int k,int l,int r,int x,int y,int p){
	if (x<=l&&r<=y){
		add(p,k,1);
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) add_e(ls[k],l,mid,x,y,p);
	if (y>mid) add_e(rs[k],mid+1,r,x,y,p);
}
void recover(int x,int id1,int id2){
	if (x==T){
		assert(id1>0&&id2<0);
		mat[-id2]=id1;
		return;
	}
	if (id[x])
		id1?id2=id[x]:id1=id[x];
	for (int i=head[x];i;i=e[i].next)
		if (dep[e[i].to]<dep[x]&&e[i^1].f){
			e[i^1].f--,e[i].f++; 
			recover(e[i].to,id1,id2);
			return;
		}
	assert(0);
}
int main(){
	scanf("%d%d",&n,&m);
	nd=m; S=++nd; T=++nd;
	dep[S]=10000; dep[T]=0;
	For(i,1,m) add(i,T,1),id[i]=-i,dep[i]=1;
	rt=build_tr(1,m,1000);
	For(i,1,n){
		scanf("%d",&tp[i]);
		if (tp[i]==0){
			int cnt,x;
			scanf("%d",&cnt);
			id[++nd]=i; dep[nd]=2333;
			for (;cnt;--cnt){
				scanf("%d",&x);
				add(nd,x,1);
			}
			add(S,nd,1);
		}
		if (tp[i]==1){
			int l,r;
			scanf("%d%d",&l,&r);
			id[++nd]=i; dep[nd]=2333;
			add_e(rt,1,m,l,r,nd);
			add(S,nd,1);
		}
		if (tp[i]==2){
			id[++nd]=i; dep[nd]=2333;
			For(j,1,3){
				int x;
				scanf("%d",&x);
				vec[i].PB(x);
				add(nd,x,1);
			}
			add(S,nd,2);
		}
	}
	int ans=0;
	for (;bfs();ans+=dfs(S,1<<30));
	For(i,1,ans) recover(S,0,0);
	For(i,1,m) if (mat[i]) ++sum[mat[i]];
	For(i,1,n) if (tp[i]==2&&sum[i]==1){
		int y=(mat[vec[i][0]]==i);
		mat[vec[i][y]]=i;
	}
	printf("%d\n",ans);
	For(i,1,m) if (mat[i]) printf("%d %d\n",mat[i],i);
}