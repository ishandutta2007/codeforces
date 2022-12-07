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
const int N=50005;
int n,m,Q,C,x;
int c[N],co[N];
vector<int> e[N];
int dep[N],fa[N];
int dfn[N],top[N],sz[N];
ll v2[N],v1[N];
void dfs1(int x){
	sz[x]=1;
	dep[x]=dep[fa[x]]+1;
	for (auto i:e[x])
		fa[i]=x,dfs1(i),sz[x]+=sz[i];
}
void dfs2(int x,int tp){
	dfn[x]=++*dfn;
	top[x]=tp;
	int k=0;
	for (auto i:e[x])
		if (i!=fa[x]&&sz[i]>sz[k])
			k=i;
	if (k) dfs2(k,tp);
	for (auto i:e[x])
		if (i!=fa[x]&&i!=k)
			dfs2(i,i);
}
const int M=10000005;
int ls[M],rs[M],tg[M],nd;
ll S[M];
void change(int &k,int l,int r,int x,int y,int v){
	if (!k) k=++nd;
	S[k]+=v*(y-x+1);
	if (x<=l&&r<=y) return tg[k]+=v,void(0);
	int mid=(l+r)/2;
	if (x<=mid) change(ls[k],l,mid,x,min(mid,y),v);
	if (y>mid) change(rs[k],mid+1,r,max(mid+1,x),y,v);
}
ll ask(int k,int l,int r,int x,int y){
	if (!k) return 0;
	if (l==x&&r==y) return S[k];
	int mid=(l+r)/2;
	ll v=1ll*tg[k]*(y-x+1);
	if (y<=mid) return ask(ls[k],l,mid,x,y)+v;
	if (x>mid) return ask(rs[k],mid+1,r,x,y)+v;
	return ask(ls[k],l,mid,x,mid)+ask(rs[k],mid+1,r,mid+1,y)+v;
}

void Change(int c,int x,int v){
	for (;x;x=fa[top[x]])
		change(c,1,n,dfn[top[x]],dfn[x],v);
}
ll Ask(int c,int x){
	ll ans=0;
	for (;x;x=fa[top[x]])
		ans+=ask(c,1,n,dfn[top[x]],dfn[x]);
	//cout<<"Q "<<ans<<' '<<c<<' '<<x<<endl;
	return ans;	
}
void change(int x,int c,int v){
	v2[c]+=2*Ask(c,x)*v;
	v2[c]+=dep[x];
	v1[c]+=v*dep[x];
	Change(c,x,v);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&Q,&C);
	For(i,1,n) scanf("%d",&c[i]);
	For(i,2,n) scanf("%d",&x),e[x].PB(i);
	For(i,1,m) scanf("%d",&co[i]);
	dfs1(1); dfs2(1,1); nd=m;
	For(i,1,n) change(i,c[i],1);
	while (Q--){
		int tp,x,y;
		scanf("%d%d",&tp,&x);
		if (tp==1){
			change(x,c[x],-1);
			scanf("%d",&c[x]);
			change(x,c[x],1);
		}
		else{
			double E2=1.0*v2[x]/n*co[x]*co[x];
			double E1=1.0*v1[x]/n*co[x];
			//cout<<"VAL "<<v2[x]<<' '<<v1[x]<<endl;
			printf("%.10lf\n",E2-2.0*E1*C+1.0*C*C);
		}
	}
}