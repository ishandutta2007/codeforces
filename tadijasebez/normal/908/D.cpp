#include <stdio.h>
#define ll long long
const int mod=1e9+7,N=1005;
int pow(int x, int k){ int ret=1;for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;return ret;}
int dp[N][N],n,a,b,x,y,z,i,j;
int main()
{
	scanf("%i %i %i",&n,&a,&b);
	x=(ll)a*pow(a+b,mod-2)%mod;
	y=(ll)b*pow(a+b,mod-2)%mod;
	z=(ll)a*pow(b,mod-2)%mod;
	for(i=n;i;i--)
		for(j=n-1;~j;j--){
			if(i+j>=n) dp[i][j]=(i+j+z)%mod;
			else dp[i][j]=((ll)x*dp[i+1][j]%mod+(ll)y*dp[i][j+i]%mod)%mod;
		}
	printf("%i\n",dp[1][0]);
	return 0;
}