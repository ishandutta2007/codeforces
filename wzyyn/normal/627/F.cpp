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
const int N=200005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n;
int a[N],b[N],aa[N];
int dfn[N],ed[N],dep[N];
int fa[N][19],A[N],B[N];
int pos1,pos2,cnt;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
bool dfs(int x,int fa,int ed){
	if (x==ed) return 1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa)
			if (dfs(e[i].to,x,ed)){
				++cnt;
				swap(aa[e[i].to],aa[x]);
				return 1;
			}
	return 0;
}
void walk(int x,int y){
	dfs(y,0,x);
}
bool OJBK(){
	For(i,1,n)
		if (aa[i]!=b[i])
			return 0;
	return 1;
}

void dfs(int x){
	dfn[x]=++*dfn;
	For(i,1,17)	fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x][0]){
			fa[e[i].to][0]=x;
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to);
		}
	ed[x]=*dfn;
}
bool isfa(int x,int y){
	return dfn[x]<=dfn[y]&&ed[y]<=ed[x];
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	For(i,0,17)
		if (tmp&(1<<i))
			x=fa[x][i];
	Rep(i,17,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
pii merge(pii x,int y){
	if (!x.fi) return pii(y,y);
	//if (!x.fi) return pii(y,y);
	int c[3];
	c[0]=x.fi; c[1]=x.se; c[2]=y;
	//sort(c,c+3,greater<int>());
	int L=LCA(c[0],c[1]);
	if (isfa(L,c[2])&&(isfa(c[2],c[0])||isfa(c[2],c[1])))
		return pii(c[0],c[1]);
	L=LCA(c[0],c[2]);
	if (isfa(L,c[1])&&(isfa(c[1],c[0])||isfa(c[1],c[2])))
		return pii(c[0],c[2]);
	L=LCA(c[1],c[2]);
	if (isfa(L,c[0])&&(isfa(c[0],c[1])||isfa(c[0],c[2])))
		return pii(c[1],c[2]);
	puts("-1");
	exit(0);
}
ll solve(int x,int y){
	int L=LCA(x,y);
	int l=1,r=dep[x]+dep[y]-2*dep[L],len=r,at=l;
	for (;x!=L;x=fa[x][0],++l) A[l]=aa[x],B[l]=b[x];
	for (;y!=L;y=fa[y][0],--r) A[r]=aa[y],B[r]=b[y];
	for (;A[1]!=B[at];++at);
	For(i,1,len)
		if (A[i]!=B[(i+at-2)%len+1])
			return 1ll<<55;
	return 1ll*min(at-1,len+1-at)*(len+1);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	For(i,1,n) if (!a[i]) pos1=i;
	For(i,1,n) if (!b[i]) pos2=i;
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(pos2);
	memcpy(aa,a,sizeof(aa));
	walk(pos1,pos2);
	if (OJBK()){
		printf("0 %d\n",cnt);
		return 0;
	}
	pii tmp(0,0);
	For(i,1,n)
		if (aa[i]!=b[i])
			tmp=merge(tmp,i);
	if (dep[tmp.fi]>dep[tmp.se])
		swap(tmp.fi,tmp.se);
	if (isfa(tmp.fi,tmp.se))
		tmp.fi=fa[tmp.fi][0];
	ll ans=1ll<<60;
	
	cnt=0;
	memcpy(aa,a,sizeof(aa));
	walk(pos1,tmp.fi);
	swap(aa[tmp.fi],aa[tmp.se]),++cnt;
	walk(tmp.se,pos2);
	ans=min(ans,cnt+solve(tmp.fi,tmp.se));
	
	cnt=0;
	memcpy(aa,a,sizeof(aa));
	walk(pos1,tmp.se);
	swap(aa[tmp.se],aa[tmp.fi]),++cnt;
	walk(tmp.fi,pos2);
	ans=min(ans,cnt+solve(tmp.fi,tmp.se));
	
	if (ans>1ll<<50) puts("-1");
	else{
		if (tmp.fi>tmp.se)
			swap(tmp.fi,tmp.se);
		printf("%d %d %lld\n",tmp.fi,tmp.se,ans);
	}
}