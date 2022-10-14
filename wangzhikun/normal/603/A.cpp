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

int n;
char ch[100010];
int dp[100010][3][2];
int main() {
	cin>>n>>(ch+1);

	for(int i=1;i<=n;i++){
		char cc = ch[i]-'0';
		memcpy(dp[i],dp[i-1],sizeof(dp[i]));
		dp[i][0][cc] = max(dp[i][0][cc],dp[i-1][0][cc^1]+1);
		dp[i][1][cc^1] = max(dp[i][1][cc^1],max(dp[i-1][1][cc],dp[i-1][0][cc])+1);
		dp[i][2][cc] = max(dp[i][2][cc],max(dp[i-1][0][cc^1],max(dp[i-1][2][cc^1],dp[i-1][1][cc^1]))+1);
	}
	int ans = 0;
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++)ans = max(ans,dp[n][i][j]);
	}
	cout<<ans<<endl;
	return 0;
}