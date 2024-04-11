#include <bits/stdc++.h>

#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}

int n,u,v;
vector<int> G[3030];
ll ans = 0;
int ysz[3030][3030];
int sz[3030];
void dfs1(int num,int fa = -1){
	sz[num] =1;
	for(auto ct:G[num]){
		if(ct == fa)continue;
		dfs1(ct,num);
		sz[num]+=sz[ct];
	}
}
struct state{
	int s,t,ss,tt;
};
vector<state> als[3030];
ll dp[3030][3030];

int cf = 0,cf2;
void dfs2(int num,int fa = -1,int cu = 0){
	als[cu].push_back((state){cf,num,cf2,fa});
	for(auto ct:G[num]){
		if(ct == fa)continue;
		dfs2(ct,num,cu+1);
	}
}

int main() {
	read(n);
	for(int i=1;i<n;i++){
		read(u,v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		dfs1(i);
		memcpy(ysz[i],sz,sizeof(sz));
		for(auto ct:G[i]){
			cf = i;
			cf2 = ct;
			dfs2(ct,i,1);
		}
	}
	for(int i=1;i<=n;i++){
		for(auto ct:als[i]){
			dp[ct.s][ct.t] = max(dp[ct.s][ct.t],max(dp[ct.s][ct.tt],dp[ct.ss][ct.t])+ysz[ct.ss][ct.s]*ysz[ct.tt][ct.t]);
			ans = max(ans,dp[ct.s][ct.t]);
		}
	}
	cout<<ans<<endl;
	return 0;
}