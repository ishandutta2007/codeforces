#include<cstdio>
#include<cstring>
#include<memory.h>
#include<algorithm>
#define ll int
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S second
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll inf=1e9+7,maxn=500010;
struct data{	ll x,y,w,id;	}p[maxn];	bool vis[maxn];
ll fa[maxn][22],mn[maxn][22],mx[maxn][22],f[maxn],head[maxn],nxt[maxn*2],vet[maxn*2],val[maxn*2],tot,n,m,dep[maxn],answ[maxn];
ll find(ll x){	return x==f[x]?x:f[x]=find(f[x]);	}
bool cmp(data a,data b){	return a.w<b.w;	}
bool cmp_id(data a,data b){	return a.id<b.id;	}
void insert(ll x,ll y,ll w){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	val[tot]=w;	}
void dfs(ll x){
	dep[x]=dep[fa[x][0]]+1;
	for(ll i=head[x];i;i=nxt[i])
	if (vet[i]!=fa[x][0]){
		mx[vet[i]][0]=val[i];
		fa[vet[i]][0]=x;
		dfs(vet[i]);
	}
}
ll Qmx(ll x,ll y){
	if (dep[x]>dep[y])	swap(x,y);
	ll t=dep[y]-dep[x],ans=0;
	For(i,0,20)	if ((1<<i)&t)	ans=max(ans,mx[y][i]),y=fa[y][i];
	FOr(i,20,0)	if (fa[x][i]!=fa[y][i])	ans=max(max(ans,mx[x][i]),mx[y][i]),x=fa[x][i],y=fa[y][i];
	return x==y?ans:max(ans,max(mx[x][0],mx[y][0]));
}
void change(ll x,ll y,ll v){
	if (dep[x]>dep[y])	swap(x,y);
	ll t=dep[y]-dep[x];
	For(i,0,20)	if ((1<<i)&t)	mn[y][i]=min(mn[y][i],v),y=fa[y][i];
    FOr(i,20,0)	if(fa[x][i]!=fa[y][i])	mn[x][i]=min(mn[x][i],v),mn[y][i]=min(mn[y][i],v),x=fa[x][i],y=fa[y][i];
	if (x!=y)	mn[x][0]=min(mn[x][0],v),mn[y][0]=min(mn[y][0],v);
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();	m=read();
	For(i,1,m)	p[i].x=read(),p[i].y=read(),p[i].w=read(),p[i].id=i;
	For(i,1,n)	f[i]=i;
	sort(p+1,p+m+1,cmp);
	For(i,1,m){
		ll x=find(p[i].x),y=find(p[i].y);
		if (x!=y)	insert(p[i].x,p[i].y,p[i].w),insert(p[i].y,p[i].x,p[i].w),f[y]=x,vis[i]=1;
	}dfs(1);
	For(i,1,20)	For(j,1,n)	fa[j][i]=fa[fa[j][i-1]][i-1],mx[j][i]=max(mx[j][i-1],mx[fa[j][i-1]][i-1]); 
	memset(mn,127,sizeof mn);
	For(i,1,m)	if (!vis[i])	answ[p[i].id]=Qmx(p[i].x,p[i].y)-1,change(p[i].x,p[i].y,p[i].w);
	FOr(i,20,1)	For(j,1,n)	mn[j][i-1]=min(mn[j][i-1],mn[j][i]),mn[fa[j][i-1]][i-1]=min(mn[fa[j][i-1]][i-1],mn[j][i]);
	For(i,1,m)	if (vis[i])	answ[p[i].id]=mn[dep[p[i].x]>dep[p[i].y]?p[i].x:p[i].y][0]-1;
	//For(i,1,m)	if (p[i].id==m-1)	writeln(vis[i]);
	For(i,1,m)	printf("%d ",answ[i]>=1e9?-1:answ[i]);
}