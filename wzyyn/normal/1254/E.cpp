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
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
using namespace std;
const int mo=1000000007;
const int N=500005;
struct edge{
	int to,next,id,fl;
}e[N*2];
int head[N],tot=1,n;
int deg[N],X[N],Y[N],dep[N];
int pre[N][2],frid[N],edid[N];
int fa[N],dfn[N],ed[N],ans=1;
int q[N],eid[N],faid[N];
void add(int x,int y,int id){
	e[++tot]=(edge){y,head[x],id};
	head[x]=tot;
}
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
bool check(int x){
	if (frid[x]&&edid[x])
		pre[edid[x]][X[edid[x]]==x]=frid[x];
	for (int i=head[x];i;i=e[i].next)
		fa[e[i].id]=e[i].id;
	int cnt=0,sum=0;
	for (int i=head[x];i;i=e[i].next){
		int xx=e[i].id,yy=pre[xx][X[xx]==x];
		if (!yy) continue;
		xx=get(xx); yy=get(yy); ++sum;
		if (xx!=yy) fa[xx]=yy; else ++cnt;
	}
	if (frid[x]&&edid[x])
		pre[edid[x]][X[edid[x]]==x]=0;
	return !cnt||(sum==deg[x]&&cnt==1);
}
void dfs(int x){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			dep[e[i].to]=dep[x]+1;
			faid[e[i].to]=i;
			dfs(e[i].to);
		}
}
int LCA(int x,int y){
	for (;x!=y;x=fa[x])
		if (dep[x]<dep[y]) swap(x,y);
	return x;
}
void walk(int S,int T){
	int L=LCA(S,T);
	//printf("%d %d %d\n",S,T,L);
	int h=1,t=dep[S]+dep[T]-2*dep[L]+1,l=t;
	q[h]=S; q[t]=T;
	for (;S!=L;){
		eid[h]=faid[S]^1;
		S=q[++h]=fa[S];
	}
	for (;T!=L;){
		eid[t-1]=faid[T];
		T=q[--t]=fa[T];
	}
	For(i,1,l-1){
		if (e[eid[i]].fl){
			puts("0");
			exit(0);
		}
		e[eid[i]].fl=1;
	}
	frid[q[1]]=e[eid[1]].id;
	edid[q[l]]=e[eid[l-1]].id;
	For(i,1,l-2){
		int x=q[i+1];
		int y=e[eid[i]].id;
		int z=e[eid[i+1]].id;
		pre[y][X[y]==x]=z;
	}
}
int main(){
	scanf("%d",&n);
	if (n==1)
		return puts("1"),0;
	For(i,1,n-1){
		scanf("%d%d",&X[i],&Y[i]);
		add(X[i],Y[i],i);
		add(Y[i],X[i],i);
		++deg[X[i]];
		++deg[Y[i]];
	}
	dfs(1);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		if (x==i) return puts("0"),0;
		if (x!=0) walk(x,i);
	}
	For(i,1,n){
		if (!check(i))
			return puts("0"),0;
		int sum=deg[i];
		for (int j=head[i];j;j=e[j].next)
			if (pre[e[j].id][X[e[j].id]==i]) --sum;
		if (edid[i]) --sum;
		if (frid[i]) --sum;
		//printf("%d %d %d\n",i,sum,deg[i]);
		For(j,1,sum) ans=1ll*ans*j%mo;
	}
	printf("%d\n",ans);
}