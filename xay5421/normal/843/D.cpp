#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#define EB emplace_back
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=100005;
const LL INF=0X3F3F3F3F3F3F3F3FLL;
int n,m,Q,dis[N];
LL d[N];
int pp,lnk[N],nxt[N],to[N],we[N];
void ae(int k1,int k2,int k3){
	to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;
}
void dij(){
	priority_queue<pair<LL,int> >q;
	auto push=[&](int x){q.emplace(-d[x],x);};
	vector<bool>vis(n+1);
	memset(d,63,sizeof(d)),d[1]=0;
	push(1);
	while(!q.empty()){
		int k1=q.top().se;q.pop();
		if(vis[k1])continue;
		vis[k1]=1;
		for(int i=lnk[k1];i;i=nxt[i])if(d[k1]+we[i]<d[to[i]]){
			d[to[i]]=d[k1]+we[i];
			push(to[i]);
		}
	}
	rep(k1,1,n)for(int i=lnk[k1];i;i=nxt[i]){
		we[i]-=d[to[i]]-d[k1];
	}
}
vector<int>A[N];
void redij(){
	rep(i,0,n)A[i].clear();
	memset(dis,63,sizeof(dis));
	dis[1]=0,A[0].EB(1);
	rep(cur,0,n){
		rep(_,0,SZ(A[cur])-1){
			int k1=A[cur][_];
			if(dis[k1]!=cur)continue;
			for(int i=lnk[k1];i;i=nxt[i]){
				if(dis[k1]+we[i]<dis[to[i]]){
					if((dis[to[i]]=dis[k1]+we[i])<=n){
						A[dis[to[i]]].EB(to[i]);
					}
				}
			}
		}
	}
	rep(k1,1,n)d[k1]+=dis[k1];
	rep(k1,1,n)for(int i=lnk[k1];i;i=nxt[i])we[i]-=dis[to[i]]-dis[k1];
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	rep(i,1,m){
		int k1,k2,k3;scanf("%d%d%d",&k1,&k2,&k3);
		ae(k1,k2,k3);
	}
	dij();
	rep(_,1,Q){
		int o,k1;scanf("%d%d",&o,&k1);
		if(o==1){
			printf("%lld\n",d[k1]>1e18?-1LL:d[k1]);
		}else{
			rep(i,1,k1){
				int k2;scanf("%d",&k2);
				++we[k2];
			}
			redij();
		}
	}
	return 0;
}