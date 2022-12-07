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
const int N=300005;
int n,m,k,x,inq[N];
int vis[N],co[N],w[N];
int dfn[N],ed[N],low[N];
int fa[N],be[N],stk[N];
vector<pii> e[N];
void tarjan(int x){
	dfn[x]=low[x]=++*dfn;
	stk[++*stk]=x; inq[x]=1;
	//cout<<x<<endl;
	for (auto i:e[x])
		if (i.fi!=fa[x]){
			if (!dfn[i.fi]){
				fa[i.fi]=x;
				tarjan(i.fi);
				low[x]=min(low[x],low[i.fi]);
			}
			else if (inq[i.fi])
				low[x]=min(low[x],dfn[i.fi]);
		}
	if (low[x]==dfn[x]){
		++*be;
		int y=19260817;
		for (;y!=x;){
			y=stk[(*stk)--];
			be[y]=*be; inq[y]=0;
		}
	}
}

namespace TREE{
	int nvis[N],fa[N];
	int spe[N],faid[N],bel[N];
	ll nco[N],f[N],g[N];
	ll sf[N],sg[N],res[N];
	vector<pii> ne[N];
	void dfs(int x){
		sf[x]=nco[x];
		if (nvis[x]) spe[x]=1;
		for (auto i:ne[x])
			if (i.fi!=fa[x]){
				fa[i.fi]=x;
				faid[i.fi]=i.se;
				dfs(i.fi);
				nvis[x]+=nvis[i.fi];
				sf[x]+=sf[i.fi];
				if (nvis[i.fi]&&nvis[i.fi]!=k)
					spe[x]=1;
			}
		//if (spe[x]) cout<<x<<' '<<nvis[x]<<endl;
	}
	void dfs1(int x){
		ll sum=sg[x]+sf[x];
		if (spe[x]) bel[x]=x;
		for (auto i:ne[x])
			if (i.fi!=fa[x]){
				bel[i.fi]=bel[x];
				sg[i.fi]=sum-sf[i.fi];
				dfs1(i.fi);
			}
	}
	void dfs2(int x){
		for (auto i:ne[x])
			if (i.fi!=fa[x]){
				dfs2(i.fi);
				if (spe[i.fi]) f[x]+=f[i.fi];
				else f[x]+=sf[i.fi];
			}
		f[x]=max(0ll,f[x]+nco[x]-w[faid[x]]);
	}
	void dfs3(int x){
		ll sum=g[x];
		for (auto i:ne[x])
			if (i.fi!=fa[x])
				if (spe[i.fi]) sum+=f[i.fi];
				else sum+=sf[i.fi];
		for (auto i:ne[x])
			if (i.fi!=fa[x]){
				g[i.fi]=sum;
				if (spe[i.fi]) g[i.fi]-=f[i.fi];
				else g[i.fi]-=sf[i.fi];
				g[i.fi]=max(0ll,g[i.fi]+nco[x]-w[i.se]);
				dfs3(i.fi);
			}
		//cout<<x<<' '<<f[x]<<' '<<g[x]<<' '<<sf[x]<<' '<<sg[x]<<' '<<fa[x]<<' '<<nco[x]<<endl;
	}
	void init(){
		For(i,1,n){
			nco[be[i]]+=co[i];
			nvis[be[i]]+=vis[i];
			//if (vis[i]) cout<<i<<' '<<be[i]<<endl;
			for (auto j:e[i])
				if (be[j.fi]!=be[i]){
					//cout<<i<<' '<<j.fi<<' '<<be[i]<<' '<<be[j.fi]<<' '<<j.se<<endl; 
					ne[be[i]].PB(pii(be[j.fi],j.se));
				}
		}
		int p=-1;
		For(i,1,*be) if (nvis[i]) p=i;
		//For(i,1,*be) cout<<i<<' '<<nvis[i]<<endl;
		//cout<<p<<endl;
		//cout<<p<<endl;
		dfs(p); dfs1(p); dfs2(p); dfs3(p);
		For(i,1,*be) if (spe[i]){
			res[i]=nco[i];
			for (auto j:ne[i])
				if (spe[j.fi]) res[i]+=(j.fi==fa[i]?g[i]:f[j.fi]);
				else res[i]+=(j.fi==fa[i]?sg[i]:sf[j.fi]);
		}
	}
	ll query(int x){
		return res[bel[x]];
	}
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,k) scanf("%d",&x),vis[x]=1;
	For(i,1,n) scanf("%d",&co[i]);
	For(i,1,m) scanf("%d",&w[i]);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(pii(y,i));
		e[y].PB(pii(x,i));
	}
	tarjan(1);
	//For(i,1,n) cout<<be[i]<<' '; cout<<endl;
	TREE::init();
	For(i,1,n) printf("%lld\n",TREE::query(be[i]));
}