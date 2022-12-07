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
const int mo=1000000007;
const int N=100005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n,val=1,ans;
int fa[N],sz[N],dfn[N],S;
int top[N],hson[N],v[N];
int S0[N*4],S1[N*4],S2[N*4],tg[N*4];
vector<pii> q[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs1(int x){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			dfs1(e[i].to);
			sz[x]+=sz[e[i].to];
			if (sz[e[i].to]>sz[hson[x]])
				hson[x]=e[i].to;
		}
}
void dfs2(int x){
	dfn[x]=++*dfn;
	if (!top[x]) top[x]=x;
	if (hson[x]){
		top[hson[x]]=top[x];
		dfs2(hson[x]);
	}
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=hson[x])
			dfs2(e[i].to);
}

void build(int k,int l,int r){
	S0[k]=r-l+1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void addv(int k,int v){
	tg[k]=(tg[k]+v)%mo;
	S2[k]=(S2[k]+2ll*S1[k]*v+1ll*S0[k]*v%mo*v)%mo;
	S1[k]=(S1[k]+1ll*S0[k]*v)%mo;
}
void pushdown(int k){
	if (!tg[k]) return;
	addv(k*2,tg[k]);
	addv(k*2+1,tg[k]);
	tg[k]=0;
}
void change(int k,int l,int r,int x,int y,int v){
	//printf("%d %d %d %d\n",l,r,x,y);
	if (l==x&&r==y) return addv(k,v);
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else{
		change(k*2,l,mid,x,mid,v);
		change(k*2+1,mid+1,r,mid+1,y,v);
	}
	S1[k]=(S1[k*2]+S1[k*2+1])%mo;
	S2[k]=(S2[k*2]+S2[k*2+1])%mo;
}
void change(int x,int dif){
	//printf("change %d %d\n",x,dif);
	dif=1ll*(dif+mo)*v[x]%mo;
	S=(S+dif)%mo;
	for (;x>1;x=fa[top[x]])
		change(1,1,n,max(2,dfn[top[x]]),dfn[x],dif);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int l,r;
		scanf("%d%d",&l,&r);
		q[l].PB(pii(i,1));
		q[r+1].PB(pii(i,-1));
		v[i]=power(r-l+1,mo-2);
		val=1ll*val*(r-l+1)%mo;
	}
	//printf("%d\n",val);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs1(1);
	dfs2(1);
	build(1,1,n);
	For(i,1,N-1){
		For(j,0,q[i].size()-1)
			change(q[i][j].fi,q[i][j].se);
		ans=(ans+1ll*S*S1[1])%mo;
		ans=(ans+mo-S2[1])%mo;
		//printf("%d %d %d %d %d\n",i,ans,S,S1[1],S2[1]);
	}
	ans=1ll*ans*val%mo;
	printf("%d\n",ans);
}