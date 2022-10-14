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

int n,d,mod;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}

int dp[1010][505][15],inv[15];
int main(){
	read(n);read(d);read(mod);
	if(n<=2){
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<15;i++){
		inv[i] = pow(i,mod-2);
	}
	dp[1][0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n/2;j++){
			
			for(int k=0;k<=d;k++){
				if(j == 0) dp[i][j][k] = (i == 1 && k == 0);
				else dp[i][j][k] = add(dp[i][j][k],dp[i][j-1][k]);
				if(j != 0){
					int cu = 1;
					for(int t=1;t<=k && t*j<i;t++){
						if(j!=1) cu = mul(cu,mul(dp[j][j-1][d-1]+t-1,inv[t]));
						//printf("  dp[%d][%d][%d] ++ dp[%d][%d][%d] cu = %d\n",i,j,k,i-t*j,j-1,k-t,cu);
						dp[i][j][k] = add(dp[i][j][k],mul(dp[i-t*j][j-1][k-t],cu));
					}
				}
				//printf("dp[%d][%d][%d] = %d\n",i,j,k,dp[i][j][k]);
			}
		}
	}
	
	int ans = dp[n][(n-1)/2][d];
	if(n%2 == 0){
		ans = add(ans,mul((mod+1)/2,mul(dp[n/2][n/2-1][d-1]+1,dp[n/2][n/2-1][d-1])));
	}
	
	cout<<ans<<endl;
	
	return 0;
}