#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
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

const int N = 200020;

ll n,u,v,depth[N],sz[N],dp1[N],dp2[N];
ll ans = 0;
vector<int> G[N];

void dfs1(int num,int fa = -1){
	dp1[num] = 1;
	sz[num] = 1;
	for(auto ct:G[num]){
		if(ct == fa)continue;
		depth[ct] = depth[num]+1;
		dfs1(ct,num);
		dp1[num]+=dp1[ct]+sz[ct];
		sz[num]+=sz[ct];
	}
}

void dfs2(int num,int fa = -1){
	ans = max(ans,dp1[num]+dp2[num]);
	//cout<<num<<' '<<dp1[num]<<' '<<dp2[num]<<endl;
	for(auto ct:G[num]){
		if(ct == fa)continue;
		dp2[ct] = dp2[num]+n-sz[num]+dp1[num]-(dp1[ct]+sz[ct])+sz[num]-sz[ct];
		dfs2(ct,num);
	}
}

int main() {
	read(n);
	for(int i=1;i<n;i++){
		read(u);read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	depth[1] = 1;
	dfs1(1);
	dfs2(1);
	cout<<ans<<endl;
	return 0;
}