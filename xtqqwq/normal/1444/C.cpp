#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k,tot,scnt,timer1,timer2; ll ans;
int v[1000005],nxt[1000005],h[500005],col[500005],bel[500005],mark1[500005],mark2[500005];
int c[500005],lab[500005],rg[500005],rt[500005],f[500005],siz[500005],hv[500005];
bool vis[500005],can[500005];
vector<int> sc[500005];
vector<pii> sh[2],nd[500005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx==fy) return;
	f[fx]=fy,siz[fy]+=siz[fx];
}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

bool dfs1(int u){
	bel[u]=scnt;
	for(int p=h[u];p;p=nxt[p]){
		if(c[v[p]]!=c[u]) continue;
		if(vis[v[p]]){
			if(col[v[p]]!=(col[u]^1)) return false;
			continue;
		}
		vis[v[p]]=1,col[v[p]]=col[u]^1;
		if(!dfs1(v[p])) return false;
	}
	return true;
}

void dfs2(int u){
	for(int p=h[u];p;p=nxt[p]){
		if(c[v[p]]!=c[u]){
			if(can[c[v[p]]]) continue;
			if(mark1[bel[v[p]]]!=timer1) mark1[bel[v[p]]]=timer1,lab[bel[v[p]]]=-1;
			if(mark2[c[v[p]]]!=timer2) mark2[c[v[p]]]=timer2,rg[c[v[p]]]=0;
			if(lab[bel[v[p]]]==-1){
				lab[bel[v[p]]]=col[v[p]]^col[u];
				sh[lab[bel[v[p]]]].pb(mp(c[v[p]],bel[v[p]]));
			}
			else if(lab[bel[v[p]]]!=(col[v[p]]^col[u])){
				if(rg[c[v[p]]]==0) ans--,rg[c[v[p]]]=1;
				else;
			}
			continue;
		}
		if(vis[v[p]]) continue;
		vis[v[p]]=1;
		dfs2(v[p]);
	}
}

int main(){
	n=readint(); m=readint(); k=readint();
	for(int i=1;i<=n;i++) c[i]=readint();
	for(int i=1;i<=m;i++) addedge(readint(),readint());
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1,scnt++,rt[scnt]=i,col[i]=0;
			if(!dfs1(i)) can[c[i]]=1;
			sc[c[i]].pb(scnt);
		}
	}
	int ccnt=0;
	for(int i=1;i<=n;i++) if(can[i]) ccnt++;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=scnt;i++) f[i]=i,siz[i]=1;
	for(int i=1;i<=k;i++){
		if(can[i]) continue;
		ans+=k-1-ccnt,timer2++;
		vector<int> gar(0);
		for(auto r:sc[i]){
			timer1++,sh[0].clear(),sh[1].clear();
			dfs2(rt[r]);
			sort(sh[0].begin(),sh[0].end());
			sort(sh[1].begin(),sh[1].end());
			for(int j=0;j<(int)sh[0].size()-1;j++) if(sh[0][j].fi==sh[0][j+1].fi&&rg[sh[0][j].fi]==0) merge(sh[0][j].se,sh[0][j+1].se);
			for(int j=0;j<(int)sh[1].size()-1;j++) if(sh[1][j].fi==sh[1][j+1].fi&&rg[sh[1][j].fi]==0) merge(sh[1][j].se,sh[1][j+1].se);
			for(auto g:sh[0]) if(rg[g.fi]==0) gar.pb(g.se),hv[g.fi]=g.se;
			for(auto g:sh[1]){
				if(rg[g.fi]==0){
					gar.pb(g.se);
					if(hv[g.fi]) nd[g.fi].pb(mp(g.se,hv[g.fi])),hv[g.fi]=0;
				}
			}
			for(auto g:sh[0]) hv[g.fi]=0;
		}
		for(auto r:gar){
			if(rg[c[rt[r]]]==0){
				for(auto g:nd[c[rt[r]]]){
					if(getf(g.fi)==getf(g.se)){
						ans--;
						break;
					}
				}
			}
			nd[c[rt[r]]].clear();
		}
		for(auto r:gar) f[r]=r,siz[r]=1;
		gar.clear();
	}
	printf("%lld\n",ans/2);
	return 0;
}