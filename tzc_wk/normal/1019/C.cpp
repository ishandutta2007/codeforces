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
const int MAXN=1e6;
int n,m,hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
bool vis[MAXN+5],in[MAXN+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),adde(u,v);
	for(int i=1;i<=n;i++) if(!vis[i]){
		in[i]=1;
		for(int e=hd[i];e;e=nxt[e]) vis[to[e]]=1;
	}
	for(int i=n;i;i--) if(in[i])
		for(int e=hd[i];e;e=nxt[e]) in[to[e]]=0;
	vector<int> res;
	for(int i=1;i<=n;i++) if(in[i]) res.pb(i);
	printf("%d\n",res.size());
	for(int x:res) printf("%d ",x);
	return 0;
}