#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=1005;
int n,sz[N],f[N],rt,ans[N],fa[N];
vector<int>e[N];
void dfs1(int k1,int k2){
	sz[k1]=1;
	for(auto&x:e[k1])if(x!=k2){
		dfs1(x,k1);
		sz[k1]+=sz[x];
		if(f[k1]<sz[x])f[k1]=sz[x];
	}
	if(f[k1]<n-sz[k1])f[k1]=n-sz[k1];
	if(f[k1]<f[rt])rt=k1;
}
vector<tuple<int,int,int> >out;
void dfs2(int k1,int k2,int&k3,int&k4){
	ans[k1]=k3;
	out.eb(k1,k2,ans[k1]-ans[k2]);
	k3+=k4;
	for(auto&x:e[k1])if(x!=k2){
		dfs2(x,k1,k3,k4);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,2,n){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v),e[v].pb(u);
	}
	f[0]=1e9;
	rt=0;
	dfs1(1,0);
	vector<bitset<1005> >dp(SZ(e[rt]));
	bitset<1005>tmp;
	tmp.set(0);
	rep(i,0,SZ(e[rt])-1){
		int x=e[rt][i];
		int cur=sz[x]<sz[rt]?sz[x]:n-sz[rt];
		dp[i]=tmp;
		tmp|=tmp<<cur;
	}
	int now=(n+1)/2;
	while(!tmp[now])--now;
	vector<int>son[2];
	per(i,SZ(e[rt])-1,0){
		int x=e[rt][i];
		int cur=sz[x]<sz[rt]?sz[x]:n-sz[rt];
		if(cur<=now&&dp[i][now-cur]){
			now-=cur;
			son[0].pb(x);
		}else{
			son[1].pb(x);
		}
	}
	int val=1,dt=1;
	for(auto&x:son[0]){
		dfs2(x,rt,val,dt);
	}
	dt=val;
	for(auto&x:son[1]){
		dfs2(x,rt,val,dt);
	}
	for(auto&x:out){
		int k1,k2,k3;
		tie(k1,k2,k3)=x;
		printf("%d %d %d\n",k1,k2,k3);
	}
	return 0;
}