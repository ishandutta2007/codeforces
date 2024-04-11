//determined
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <complex>
#include <cassert>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) //cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}
const int N = 200020;
int mod = 998244353;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int mpow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(mpow(a,b/2))) : sq(mpow(a,b/2)));}

ll n,dp[N][3] = {0},cf;
vector<int> G[N];
void dfs(int num){
	if(G[num].size() == 0){
		dp[num][2] = 1;
		return;
	}
	dp[num][0] = 1;dp[num][1] = 0;dp[num][2] = 0;
	ll ndp[3];
	for(auto ct:G[num]){
		dfs(ct);
		ndp[0] = mul(dp[num][0],add(dp[ct][0],dp[ct][2]));
		ndp[1] = add(mul(dp[num][1],add(dp[ct][0],dp[ct][2])),mul(dp[num][0],add(dp[ct][1],dp[ct][2])));
		ndp[2] = add(mul(dp[num][1],add(dp[ct][1],dp[ct][2])),mul(dp[num][2],(dp[ct][0]+dp[ct][1]+dp[ct][2]*2)%mod));
		memcpy(dp[num],ndp,sizeof(ndp));
	}
}
int main(){
	read(n);
	for(int i=2;i<=n;i++){
		read(cf);
		G[cf].push_back(i);
	}
	dfs(1);
	cout<<add(dp[1][0],dp[1][2])<<endl;
	return 0;
}