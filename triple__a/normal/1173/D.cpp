#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
const int mod=998244353;
const int maxn=400007;

int p[maxn],cnt=0,n;
int h[maxn],fz[maxn];
ll ans=1;

bool vis[maxn];
struct edge{
	int to,next;
}ed[maxn];
 
void init(int u,int v){
	ed[cnt].to=v;
	ed[cnt].next=p[u];
	p[u]=cnt++;
}

void dfs_size(int u){
	vis[u]=1;
	for (int i=p[u];i!=-1;i=ed[i].next){
		int v=ed[i].to;
		if (!vis[v]){
			dfs_size(v);
			h[u]+=h[v];
			fz[u]++;
		} 
	}
} 

ll factor(int u){
	ll ans=1;
	while(u>0){
		ans=(ans*u)%mod;
		u--;
	}
	return ans;
}

int main(){
	memset(vis,0,sizeof(vis));
	memset(fz,0,sizeof(fz));
	memset(h,0,sizeof(h));
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		p[i]=-1;
		h[i]=1;
	}
	for (int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		init(u,v);
		init(v,u);
	}
	dfs_size(1);
	ans=(n*factor(fz[1]))%mod;
	for (int i=2;i<=n;++i){
		ans=(ans*(fz[i]+1))%mod;
		ans=(ans*(factor(fz[i])))%mod;
	}
	printf("%lld\n",ans);
	return 0; 
}