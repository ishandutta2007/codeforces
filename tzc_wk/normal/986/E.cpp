#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
const int MOD=1e9+7; 
const int MAXN=1e5+5;
const int MAXV=1e7+5;
int n,q,qn,a[MAXN];
int hd[MAXN],nxt[MAXN<<1],to[MAXN<<1],ec=0;
void adde(int u,int v){
	to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;
}
int fa[MAXN][22],dep[MAXN];
void dfs(int x,int f){
	fa[x][0]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs(y,x);
	}
}
int getlca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;~i;i--) if(dep[x]-(1<<i)>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=20;~i;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
vector<pii> fac[MAXN];
struct Query{
	int w,x,id,mul;
} qu[MAXN<<2];
int qpow(int x,int e){
	int ret=1;
	while(e){
		if(e&1) ret=1ll*ret*x%MOD;
		x=1ll*x*x%MOD;e>>=1;
	} return ret;
}
int ans[MAXN];
int sum[MAXV/5][24];
vector<int> qv[MAXN];
int pid[MAXV],pr[MAXV/5],pcnt=0;
bitset<MAXV> vis;
void prework(){
	for(int i=2;i<MAXV;i++){
		if(!vis[i]){pr[++pcnt]=i;pid[i]=pcnt;}
		for(int j=1;j<=pcnt&&pr[j]*i<MAXV;j++){
			vis[pr[j]*i]=1;if(i%pr[j]==0) break;
		}
	}
}
void calc(int x){
	ffe(it,fac[x]) sum[pid[it->fi]][it->se]++;
	ffe(it,qv[x]){
		int id=*it,tmp=qu[id].w;
		vector<pii> ff;
		for(int i=2;i*i<=tmp;i++){
			if(tmp%i==0){
				int cnt=0;
				while(tmp%i==0) tmp/=i,cnt++;
				ff.pb(mp(i,cnt));
			}
		}
		if(tmp>1) ff.pb(mp(tmp,1));
		int tot_mul=1;
		for(int i=0;i<ff.size();i++){
			int pw=1,val=ff[i].fi;
			for(int j=1;j<=ff[i].se;j++) pw*=ff[i].fi;
			for(int j=1;val<MAXV;j++,val*=ff[i].fi){
				int cnt=sum[pid[ff[i].fi]][j];
				int mul=qpow(min(val,pw),cnt);
				tot_mul=1ll*tot_mul*mul%MOD;
			}
		}
		if(qu[id].mul==1) ans[qu[id].id]=1ll*ans[qu[id].id]*tot_mul%MOD;
		else ans[qu[id].id]=1ll*ans[qu[id].id]*qpow(tot_mul,MOD-2)%MOD;
	}
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==fa[x][0]) continue;calc(y);
	}
	ffe(it,fac[x]) sum[pid[it->fi]][it->se]--;
}
int main(){
	prework();
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);adde(u,v);adde(v,u);
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int tmp=a[i];
		for(int j=2;j*j<=tmp;j++){
			if(tmp%j==0){
				int cnt=0;
				while(tmp%j==0) tmp/=j,cnt++;
				fac[i].pb(mp(j,cnt));
			}
		}
		if(tmp>1) fac[i].pb(mp(tmp,1));
	}
	dfs(1,0);
	for(int i=1;i<=20;i++) for(int j=1;j<=n;j++)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);ans[i]=1;
		int lca=getlca(u,v);
		qu[++qn]={w,u,i,1};qu[++qn]={w,v,i,1};
		qu[++qn]={w,lca,i,-1};if(lca!=1) qu[++qn]={w,fa[lca][0],i,-1};
	}
	for(int i=1;i<=qn;i++) qv[qu[i].x].pb(i);calc(1);
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}