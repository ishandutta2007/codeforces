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

int mod = 1e9+7;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int qpow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(qpow(a,b/2))) : sq(qpow(a,b/2)));}

int n,p,dp[300][300] = {0},C[300][300],pp[300],p1[300];
int main() {
	read(n);read(p);
	dp[0][0] = 1;
	C[0][0] = 1;
	pp[0] = p1[0] = 1;
	for(int i=1;i<=250;i++){
		pp[i] = mul(pp[i-1],p);
		p1[i] = mul(p1[i-1],p-1);
		C[i][0] = 1;
		for(int j=1;j<=i;j++){
			C[i][j] = add(C[i-1][j-1],C[i-1][j]);
			//cout<<i<<' '<<j<<' '<<C[i][j]<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<=j;k++){
				if(k == j) dp[i][j] = add(dp[i][j],mul(dp[i-1][k],mul(sub(pp[k],p1[k]),p1[n-j])));
				else dp[i][j] = add(dp[i][j],mul(dp[i-1][k],mul(C[n-k][n-j],mul(pp[k],p1[n-j]))));
			}
		}
	}
	cout<<dp[n][n]<<endl;
	return 0;
}