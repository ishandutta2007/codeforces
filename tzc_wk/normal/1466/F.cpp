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
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MOD=1e9+7;
const int MAXN=5e5;
int n,m,hd[MAXN+5],nxt[MAXN*2+5],to[MAXN*2+5],id[MAXN*2+5],ec=0;
int qpow(int x,int e){int ret=1;for(;e;x=1ll*x*x%MOD,e>>=1) if(e&1) ret=1ll*ret*x%MOD;return ret;}
void adde(int u,int v,int x){to[++ec]=v;id[ec]=x;nxt[ec]=hd[u];hd[u]=ec;}
int f[MAXN+5],ff[MAXN+5],eu[MAXN+5],ev[MAXN+5];
ll calc(int x,int y){return 1ll*f[x]*ff[x-y]%MOD*ff[y]%MOD;}
bool hav1=0;int cn=0;
bool vis[MAXN+5],hav[MAXN+5];
int fa[MAXN+5];
vector<int> vv;
void dfs(int x){
	if(vis[x]) return;
	vis[x]=1;cn++;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];
		if(y==x) hav1=1,vv.pb(id[e]);
		else vv.pb(id[e]),dfs(y);
	}
}
int find(int x){return (fa[x]==x)?fa[x]:fa[x]=find(fa[x]);}
bool merge(int x,int y){
	x=find(x);y=find(y);
	if(x!=y) return fa[x]=y,hav[y]|=hav[x],1;
	else return 0;
}
int main(){
	scanf("%d%d",&m,&n);f[0]=1;
	for(int i=1;i<=n;i++) f[i]=1ll*f[i-1]*i%MOD;
	ff[n]=qpow(f[n],MOD-2);
	for(int i=n-1;~i;i--) ff[i]=1ll*ff[i+1]*(i+1)%MOD;
	for(int i=1;i<=m;i++){
		int k;scanf("%d",&k);
		if(k==1){int x;scanf("%d",&x);adde(x,x,i);eu[i]=ev[i]=x;}
		else{int u,v;scanf("%d%d",&u,&v);adde(u,v,i);adde(v,u,i);eu[i]=u;ev[i]=v;}
	}
	ll ans=1;vector<int> anss;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			hav1=0;cn=0;vv.clear();dfs(i);
			if(hav1) ans=1ll*ans*qpow(2,cn)%MOD;
			else{
				int sum=0;
				for(int j=0;j<=cn;j+=2) sum=(sum+calc(cn,j))%MOD;
				ans=1ll*ans*sum%MOD;
			}
			sort(vv.begin(),vv.end());bool used=0;
			ffe(it,vv){
				int id=*it;
				if(eu[id]==ev[id]){
					if(hav[find(eu[id])]) continue;
					hav[find(eu[id])]=1;anss.pb(id);
				}
				if(eu[id]!=ev[id]){
					if(hav[find(eu[id])]&&hav[find(ev[id])]) continue;
					if(merge(eu[id],ev[id])) anss.pb(id);
				}
			}
		}
	}
	printf("%lld %d\n",ans,anss.size());sort(anss.begin(),anss.end());
	ffe(it,anss) printf("%d ",*it);
	return 0;
}
/*
7 4
2 1 2
1 2
1 4
2 2 4
1 3
2 3 4
2 2 3

9 7
2 1 2
1 2
1 4
2 2 4
1 3
2 3 4
2 2 3
2 5 6
2 6 7

4 4
2 1 2
2 2 3
2 3 4
2 4 1
*/