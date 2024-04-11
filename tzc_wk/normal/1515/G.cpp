#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned int u32;
typedef unsigned long long u64;
const int MAXN=2e5;
ll _gcd(ll x,ll y){return (!y)?x:_gcd(y,x%y);}
int n,m,qu,hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],val[MAXN+5],ec=0;
void adde(int u,int v,int w){to[++ec]=v;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
int dfn[MAXN+5],low[MAXN+5],vis[MAXN+5],stk[MAXN+5],tim,tp=0,ccnt=0,cmp=0,bel[MAXN+5];
ll d[MAXN+5],dis[MAXN+5];pair<int,ll> cyc[MAXN+5];
void tarjan(int x){
	dfn[x]=low[x]=++tim;stk[++tp]=x;vis[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e];
		if(!dfn[y]) dis[y]=dis[x]+z,tarjan(y),chkmin(low[x],low[y]);
		else if(vis[y]) cyc[++ccnt]=mp(y,dis[x]-dis[y]+z),chkmin(low[x],dfn[y]);
	} if(dfn[x]==low[x]){
		cmp++;int o;do{
			o=stk[tp--];vis[o]=0;bel[o]=cmp;
		} while(o^x);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),adde(u,v,w);
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=ccnt;i++) d[bel[cyc[i].fi]]=_gcd(d[bel[cyc[i].fi]],cyc[i].se);
	scanf("%d",&qu);while(qu--){
		int x,s,t;scanf("%d%d%d",&x,&s,&t);
		printf("%s\n",(s%_gcd(d[bel[x]],t))?"NO":"YES");
	}
	return 0;
}