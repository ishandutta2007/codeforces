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
const int MAXN=3e5;
int n,m,X,f[MAXN+5];ll a[MAXN+5];
int find(int x){return (!f[x])?x:f[x]=find(f[x]);}
bool merge(int x,int y){x=find(x);y=find(y);return (x==y)?0:(f[x]=y,1);}
int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],id[MAXN*2+5],ec=0,deg[MAXN+5];
bool vis[MAXN+5];
void adde(int u,int v,int w){to[++ec]=v;id[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
int main(){
	scanf("%d%d%d",&n,&m,&X);ll sum=0;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i];
	if(sum<1ll*X*(n-1)) return puts("NO"),0;
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		if(merge(u,v)) adde(u,v,i),adde(v,u,i),deg[u]++,deg[v]++;
	} queue<int> q;
	for(int i=1;i<=n;i++) if(deg[i]==1) q.push(i);
	vector<int> v1,v2;
	while(!q.empty()){
		int x=q.front();q.pop();vis[x]=1;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=id[e];
			if(!vis[y]){
				if(a[x]>=X) v1.pb(z),a[y]=a[x]+a[y]-X;
				else v2.pb(z);
				if(--deg[y]==1) q.push(y);
			}
		}
	} printf("YES\n");
	for(int i=0;i<v1.size();i++) printf("%d\n",v1[i]);
	for(int i=(int)(v2.size())-1;~i;i--) printf("%d\n",v2[i]);
	return 0;
}