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
const int mo=998244353;
const int N=150005;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n,Q,S,t[N];
int sz[N],a[N],dfn[N],ed[N];
int hson[N],fa[N],top[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void change(int x,int v){
	for (;x<=n;x+=x&(-x))
		t[x]=(t[x]+v)%mo;
}
int ask(int x){
	int s=0;
	for (;x;x-=x&(-x))
		s=(s+t[x])%mo;
	return s;
}
void dfs(int x){
	sz[x]=1;
	dfn[x]=++*dfn;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			dfs(e[i].to);
			sz[x]+=sz[e[i].to];
			if (sz[e[i].to]>sz[hson[x]])
				hson[x]=e[i].to;
		}
	ed[x]=*dfn;
}
void dfss(int x){
	if (!top[x]) top[x]=x;
	top[hson[x]]=top[x];
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x])
			dfss(e[i].to);
}
void addv(int x,int y){
	S=(S+1ll*sz[x]*y)%mo;
	a[x]=(a[x]+y)%mo;
	int val=1ll*(n-sz[hson[x]]-sz[x]+mo)*y%mo;
	change(dfn[x]+1,val);
	change(ed[x]+1,mo-val);
}
int askv(int x){
	int res=S;
	res=(res+ask(dfn[x]))%mo;
	res=(res+1ll*(n-sz[x])*a[x])%mo;
	for (int i=top[x];i!=1;i=top[fa[i]])	
		res=(res+1ll*(sz[hson[fa[i]]]-sz[i])*a[fa[i]])%mo;
	return res;
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1); dfss(1);
	int val=power(n,mo-2);
	while (Q--){
		int tp,x,y;
		scanf("%d%d",&tp,&x);
		if (tp==1){
			scanf("%d",&y);
			addv(x,y);
		}
		else
			printf("%d\n",1ll*val*askv(x)%mo);
	}
}