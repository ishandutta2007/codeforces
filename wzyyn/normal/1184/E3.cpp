#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=100005;
const int M=1000005;
struct Edge{
	int x,y,v,id;
	bool operator <(const Edge &a)const{
		return v<a.v;
	}
}E[M];
struct edge{
	int to,next,v,id;
}e[N*2];
int head[N],tot;
int fa[N],n,m;
int used[M],ans[M];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void add(int x,int y,int v,int id){
	e[++tot]=(edge){y,head[x],v,id};
	head[x]=tot;
}
int Fa[N][18];
int Fav[N][18];
int Mnv[N][18];
int Faid[N];
int dep[N];
void dfs(int x){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=Fa[x][0]){
			dep[e[i].to]=dep[x]+1;
			Faid[e[i].to]=e[i].id;
			Fav[e[i].to][0]=e[i].v;
			Fa[e[i].to][0]=x;
			dfs(e[i].to);
		}
}
int Query(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y],ans=0;
	For(i,0,16) if (tmp&(1<<i))
		ans=max(ans,Fav[x][i]),x=Fa[x][i];
	if (x==y) return ans;
	Rep(i,16,0) if (Fa[x][i]!=Fa[y][i]){
		ans=max(ans,max(Fav[x][i],Fav[y][i]));
		x=Fa[x][i]; y=Fa[y][i];
	}
	return max(ans,max(Fav[x][0],Fav[y][0]));
}
void insert(int x,int y,int v){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	For(i,0,16) if (tmp&(1<<i))
		Mnv[x][i]=min(Mnv[x][i],v),x=Fa[x][i];
	if (x==y) return;
	Rep(i,16,0) if (Fa[x][i]!=Fa[y][i]){
		Mnv[x][i]=min(Mnv[x][i],v);
		Mnv[y][i]=min(Mnv[y][i],v);
		x=Fa[x][i]; y=Fa[y][i];
	}
	Mnv[x][0]=min(Mnv[x][0],v);
	Mnv[y][0]=min(Mnv[y][0],v);
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].v);
		E[i].id=i;
	}
	sort(E+1,E+m+1);
	For(i,1,n) fa[i]=i;
	For(i,1,m){
		int x=get(E[i].x),y=get(E[i].y);
		if (x!=y){
			used[E[i].id]=1;
			add(E[i].x,E[i].y,E[i].v,E[i].id);
			add(E[i].y,E[i].x,E[i].v,E[i].id);
			fa[x]=y;
		}
	}
	dfs(1);
	For(i,1,16) For(j,1,n){
		Fa[j][i]=Fa[Fa[j][i-1]][i-1];
		Fav[j][i]=max(Fav[j][i-1],Fav[Fa[j][i-1]][i-1]);
	}
	For(i,0,16) For(j,1,n) Mnv[j][i]=1000000000;
	For(i,1,m)
		if (!used[E[i].id]){
			ans[E[i].id]=Query(E[i].x,E[i].y);
			insert(E[i].x,E[i].y,E[i].v);
		}
	Rep(i,16,1) For(j,1,n){
		Mnv[j][i-1]=min(Mnv[j][i-1],Mnv[j][i]);
		Mnv[Fa[j][i-1]][i-1]=min(Mnv[Fa[j][i-1]][i-1],Mnv[j][i]);
	}
	For(i,2,n)
		ans[Faid[i]]=Mnv[i][0];
	For(i,1,m) printf("%d\n",ans[i]);
}