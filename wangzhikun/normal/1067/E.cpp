#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int n,k,u,v,md,dep,st[500050],stn = 0,rt,ok = 1;
vector<int> G[500050];
int mod = 998244353;
inline int sq(int x){return 1ll*x*x%mod;}
inline int sub(int a,int b){return a<b?a-b+mod:a-b;}
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int pow(int a,int b){if(b == 0)return 1;return b&1?mul(sq(pow(a,b/2)),a):sq(pow(a,b/2));}
inline int inv(int a){return pow(a,mod-2);}
ll dp[500050][2],ndp[2],npos[2],pos[500050][2];
void dfs(int num,int fa){
	pos[num][0]=1;pos[num][1] = 1;
	for(auto ct:G[num]){
		if(ct == fa)continue;
		dfs(ct,num);
		ndp[0] = dp[num][0]*pos[ct][1]+dp[ct][1]*pos[num][0];
		ndp[1] = (dp[ct][0]+dp[ct][1])*pos[num][1]+dp[num][1]*(pos[ct][1]+pos[ct][0])+pos[num][0]*pos[ct][0]+dp[num][0]*pos[ct][0]+dp[ct][0]*pos[num][0];
		npos[1] = pos[num][0]*pos[ct][0]+pos[num][1]*(pos[ct][0]+pos[ct][1]);
		npos[0] = pos[num][0]*pos[ct][1];
		pos[num][0] = npos[0]%mod;pos[num][1] = npos[1]%mod;
		dp[num][0] = ndp[0]%mod;dp[num][1] = ndp[1]%mod;
	}
	//cout<<num<<' '<<pos[num][0]<<' '<<pos[num][1]<<' '<<dp[num][0]<<' '<<dp[num][1]<<endl;
}
int main() {
	read(n);
	for(int i=1;i<n;i++){
		read(u);read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,-1);
	cout<<mul(add(dp[1][0],dp[1][1]),2)<<endl;
	return 0;
}