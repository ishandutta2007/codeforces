#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=100005;
int n,S,id[N];
LL dis[N],dep[N];
int pp,lnk[N],nxt[N*2],to[N*2],we[N*2];
void ae(int k1,int k2,int k3){to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void dfs(int k1,int k2){
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		dep[to[i]]=dep[k1]+we[i];
		dfs(to[i],k1);
	}
}
void pre(){
	auto up=[&](){
		rep(i,1,n)dis[i]=max(dis[i],dep[i]);
	};
	dep[1]=0,dfs(1,0),up();
	int k1=max_element(dep+1,dep+1+n)-dep;
	dep[k1]=0,dfs(k1,0),up();
	k1=max_element(dep+1,dep+1+n)-dep;
	dep[k1]=0,dfs(k1,0),up();
}
bool vis[N];
int cnt[N],fa[N],sz[N];
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		int k1,k2,k3;scanf("%d%d%d",&k1,&k2,&k3);
		ae(k1,k2,k3),ae(k2,k1,k3);
	}
	pre();
	int Q;scanf("%d",&Q);
	rep(i,1,n)id[i]=i;
	rep(_,1,Q){
		sort(id+1,id+1+n,[&](int k1,int k2){return dis[k1]>dis[k2];});
		LL num;scanf("%lld",&num);
		
		int mx=1;
		rep(i,1,n)fa[i]=i,sz[i]=1,cnt[i]=0,vis[i]=0;
		cnt[1]=n;
		int j=1;
		int ans=0;
		rep(__,1,n){
			int k1=id[__];
			auto mer=[&](int k1,int k2){
				k1=fd(k1),k2=fd(k2);
				if(k1!=k2){
					--cnt[sz[k1]];
					--cnt[sz[k2]];
					fa[k1]=k2,sz[k2]+=sz[k1],sz[k1]=0;
					++cnt[sz[k2]];
					mx=max(mx,sz[k2]);
				}
			};
			auto del=[&](int k1){
				k1=fd(k1);
				--cnt[sz[k1]];
				--sz[k1];
				++cnt[sz[k1]];
				if(!cnt[mx])--mx;
			};
			for(int i=lnk[k1];i;i=nxt[i])if(vis[to[i]]){
				mer(k1,to[i]);
			}
			vis[k1]=1;
			while(dis[id[j]]>dis[k1]+num){
				del(id[j++]);
			}
			ans=max(ans,mx);
		}
		printf("%d\n",ans);
	}
	return 0;
}