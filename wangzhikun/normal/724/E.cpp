//determined
#include <cmath>
#include <cstdio>
#include <cstring>
#include <complex>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl

using namespace std;
typedef long long ll;

template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}

int cu = 0;
ll n,c,p[10010],s[10010],dp[2][10010];

int main(){
	read(n);read(c);
	for(int i=1;i<=n;i++)read(p[i]);
	for(int i=1;i<=n;i++)read(s[i]);
	for(int i=0;i<=n;i++)dp[cu][i] = 1e18;
	dp[cu][0] = 0;
	for(int i=1;i<=n;i++){
		cu^=1;
		dp[cu][0] = dp[cu^1][0]+p[i];
			//cout<<"dp["<<cu<<"]["<<0<<"] = "<<dp[cu][0]<<endl;
		for(int j=1;j<=n;j++){
			dp[cu][j] = min(dp[cu^1][j-1]+s[i],dp[cu^1][j]+p[i]+j*c);
			//cout<<"dp["<<cu<<"]["<<j<<"] = "<<dp[cu][j]<<endl;
		}
	}
	ll ans = 1e18;
	for(int i=0;i<=n;i++)ans = min(ans,dp[cu][i]);
	cout<<ans<<endl;
	return 0;
}