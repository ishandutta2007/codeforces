#include<cstdio>
#include<algorithm>
using namespace std;
const int max_n=1e5+5;
char S[max_n];
const int max_R=5e4+5;
unsigned int dp[2][max_R];
int main()
{
	int n;
	scanf("%d%s",&n,S+1);
	dp[0][0]=1;
	int L=0,R=0;
	for(int i=1;i<=n;++i)
	{
		int y=i&1,x=y^1;
		if(S[i]=='?')
		{
			if(L==0)
				dp[y][1]=dp[x][0]*25;
			else
				dp[y][L-1]=0;
			dp[y][L]=0;
			for(int j=max(L,1);j<=R;++j)
			{
				dp[y][j+1]=dp[x][j]*25;
				dp[y][j-1]+=dp[x][j];
			}
			L=max(L-1,0),R=min(R+1,n-i);
		}
		else
		{
			for(int j=L;j<=R;++j)
				dp[y][j+1]=dp[x][j];
			++L,R=min(R+1,n-i);
		}
		while(L<=R&&!dp[y][L])
			++L;
		while(L<=R&&!dp[y][R])
			--R;
		if(L>R)
		{
			puts("0");
			return 0;
		}
	}
	printf("%u\n",dp[n&1][0]);
	return 0;
}