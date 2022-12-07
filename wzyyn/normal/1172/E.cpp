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
const int N=400005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n,Q;
int sz[N],dep[N],fa[N],co[N];
int top[N],dfn[N],ed[N],pos[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs1(int x){
	sz[x]=1;
	dep[x]=dep[fa[x]]+1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			dfs1(e[i].to);
			sz[x]+=sz[e[i].to];
		}
}
void dfs2(int x,int tp){
	dfn[x]=++*dfn; pos[*dfn]=x;
	int k=0; top[x]=tp; ed[x]=x;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&sz[e[i].to]>sz[k])
			k=e[i].to;
	if (k) dfs2(k,tp),ed[x]=ed[k];
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=k)
			dfs2(e[i].to,e[i].to);
}
struct info{
	ll sum;
	int sl,sr,s;
	info operator +(const info &a)const{
		info ans;
		ans.sum=sum+a.sum+2ll*sr*a.sl;
		ans.s=s+a.s;
		ans.sl=(sl==s?sl+a.sl:sl);
		ans.sr=(a.sr==a.s?sr+a.sr:a.sr);
		return ans;
	}
}t[N*3],T[N*3];
int L,stk[25],vis[N];
ll ans[N];
void update(int k){
	for (k=(k+L)>>1;k;k>>=1)
		t[k]=t[k*2]+t[k*2+1];
}
info query(int l,int r){
	l=l+L-1,r=r+L+1;
	info ls=(info){0,0,0,0},rs=ls;
	for (;l^r^1;l>>=1,r>>=1){
		if (!(l&1)) ls=ls+t[l^1];
		if (r&1) rs=t[r^1]+rs;
	}
	return ls+rs;
}
void build(){
	for (L=1;L<=n+2;L<<=1);
	For(i,1,n){
		t[dfn[i]+L]=(info){1,1,1,1};
		T[dfn[i]+L].s=1;
	}
	Rep(i,n,1){
		int x=pos[i]; update(i);
		if (top[x]==x&&x!=1){
			info tmp=query(dfn[x],dfn[ed[x]]);
			int f=fa[x],pf=dfn[fa[x]];
			t[pf+L].sum+=tmp.sum+2ll*t[pf+L].sl*tmp.sl;
			T[pf+L].sum+=tmp.sum;
			t[pf+L].s+=tmp.sl;
			t[pf+L].sl+=tmp.sl;
			t[pf+L].sr+=tmp.sl;
		}
	}
}
void Update(int x){
	int cnt=0;
	for (int y=top[x];y!=1;y=top[fa[y]])
		stk[++cnt]=y;
	Rep(i,cnt,1){
		int x=stk[i];
		info tmp=query(dfn[x],dfn[ed[x]]);
		int f=fa[x],pf=dfn[fa[x]];
		if (vis[f]) swap(t[pf+L],T[pf+L]);
		t[pf+L].s-=tmp.sl;
		t[pf+L].sl-=tmp.sl;
		t[pf+L].sr-=tmp.sl;
		t[pf+L].sum-=tmp.sum+2ll*t[pf+L].sl*tmp.sl;
		T[pf+L].sum-=tmp.sum;
		if (vis[f]) swap(t[pf+L],T[pf+L]);
	}
	swap(t[dfn[x]+L],T[dfn[x]+L]);
	update(dfn[x]);
	vis[x]^=1;
	For(i,1,cnt){
		int x=stk[i];
		info tmp=query(dfn[x],dfn[ed[x]]);
		int f=fa[x],pf=dfn[fa[x]];
		if (vis[f]) swap(t[pf+L],T[pf+L]);
		t[pf+L].sum+=tmp.sum+2ll*t[pf+L].sl*tmp.sl;
		T[pf+L].sum+=tmp.sum;
		t[pf+L].s+=tmp.sl;
		t[pf+L].sl+=tmp.sl;
		t[pf+L].sr+=tmp.sl;
		if (vis[f]) swap(t[pf+L],T[pf+L]);
		update(pf);
	}
}
vector<pii> vec[N];
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&Q);
	For(i,1,n){
		scanf("%d",&co[i]);
		vec[co[i]].PB(pii(i,0));
	}
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs1(1);
	dfs2(1,1);
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		vec[co[x]].PB(pii(x,i));
		vec[co[x]=y].PB(pii(x,i));
	}
	build();
	For(i,1,n){
		int sz=vec[i].size();
		ans[0]+=1ll*n*n;
		for (int j=0,k;j<sz;j=k+1){
			for (k=j;k+1<sz&&vec[i][k+1].se==vec[i][j].se;++k);
			ans[vec[i][j].se]-=query(1,dfn[ed[1]]).sum;
			For(p,j,k) Update(vec[i][p].fi);
			ans[vec[i][j].se]+=query(1,dfn[ed[1]]).sum;
		}
		For(j,0,sz-1)
			if (vis[vec[i][j].fi])
				Update(vec[i][j].fi);
	}
	For(i,1,Q) ans[i]+=ans[i-1];
	For(i,0,Q) printf("%lld\n",1ll*n*n*n-ans[i]);
}