#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n;
ll f[2005][1005][2];
int main()
{
	scanf("%d",&n);
	f[0][0][1]=1;
	for(int i=1;i<=2*n;i++)
	for(int j=0;j<=n;j++)
	{
		if((i&1)!=(j&1))continue;
		if(j>min(i,2*n-i))continue;
		if(j==0)
		{
			f[i][j][0]=f[i-1][j+1][1];
			f[i][j][1]=f[i-1][j+1][0]+1;
		}
		else if(j==i)
		{
			f[i][j][0]=f[i-1][j-1][1];
			f[i][j][1]=f[i-1][j-1][0]+1;
		}
		else
		{
			f[i][j][0]=f[i-1][j-1][1]+f[i-1][j+1][0];
			f[i][j][1]=f[i-1][j-1][0]+f[i-1][j+1][0]+1;
			if(f[i][j][0]>=MOD)f[i][j][0]-=MOD;
			if(f[i][j][1]>=MOD)f[i][j][1]-=MOD;
		}
	}
	printf("%I64d\n",f[2*n][0][0]%MOD);
	return 0;
}