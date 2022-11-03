#include<queue>
#include<ctime>
#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S i
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=4e5+6;
ll tot=1,n,m,fa[N],head[N],nxt[N],vet[N],val[N],q[N],L[N],R[N];	bool vis[N],ff[N],cho[N];
void insert(ll x,ll y,ll w){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	val[tot]=w;		}
void dfs(ll x,ll pre){
	ff[x]=1;	ll vis_f=0;
	for(ll i=head[x];i;){
		if (vet[i]==pre&&!vis_f){	++vis_f;	i=nxt[i];	continue;	}
		if (ff[vet[i]]){
			fa[vet[i]]=i^1;
			for(ll now=x;now!=vet[i];now=vet[fa[now]])	
			q[++tot]=now;
			q[++tot]=vet[i];
			return;
		}fa[vet[i]]=i^1;	dfs(vet[i],x);
		if (tot)	return;
		i=nxt[i];
	}
}
void Dfs(ll x){
	vis[x]=1;
	for(ll i=head[x];i;i=nxt[i])
	if (!vis[vet[i]])	cho[abs(val[i])]=val[i]<0,Dfs(vet[i]);
}
int main(){
//	freopen("a.in","r",stdin);
	m=read();	n=read();
	For(i,1,m){
		ll sz=read();
		For(j,1,sz){
			ll x=read(),opt=x>0;	x=abs(x);
			if (L[x])	R[x]=opt?i:-i;
			else	L[x]=opt?i:-i;
		}
	}
	For(i,1,n)if (L[i]){
		if (!R[i])	vis[abs(L[i])]=1,cho[i]=L[i]>0;
		else{
			if((L[i]>0)^(R[i]>0))	insert(abs(L[i]),abs(R[i]),(L[i]>0)?i:-i),insert(abs(R[i]),abs(L[i]),(R[i]>0)?i:-i);
			else	cho[i]=L[i]>0,vis[abs(L[i])]=vis[abs(R[i])]=1;
		}
	}
	For(i,1,m)	if (vis[i])	Dfs(i);
	For(i,1,m)if (!vis[i]){
		tot=0;	dfs(i,0);
		if (!tot)	return puts("NO"),0;
//		printf("------------------------");
		For(x,1,tot)	vis[q[x]]=1;
		For(x,1,tot)	cho[abs(val[fa[q[x]]])]=val[fa[q[x]]]>0;
		For(x,1,tot)	Dfs(q[x]);
	}
	puts("YES");
	For(i,1,n)	putchar(cho[i]?'1':'0');
}
/*
f[i][j]=
*/