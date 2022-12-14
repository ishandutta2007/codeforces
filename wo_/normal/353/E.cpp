#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char ch[1100100];
int N;
char tmp[1100100];

int dp[1100100][2];

int solve()
{
	dp[0][0]=1<<29;
	dp[0][1]=0;
	dp[1][0]=1;
	dp[1][1]=1<<29;
	for(int i=2;i<N;i++)
	{
		dp[i][0]=1<<29;dp[i][1]=1<<29;
		
		dp[i][0]=min(dp[i][0],dp[i-1][1]+1);
		if(tmp[i-1]==tmp[i-2]){
			dp[i][0]=min(dp[i][0],dp[i-1][0]);
		}else{
			dp[i][0]=min(dp[i][0],dp[i-1][0]+1);
		}
		dp[i][1]=min(dp[i][1],dp[i-1][0]);
	}
	return dp[N-1][0];
}

int main()
{
	scanf("%s",ch);
	N=strlen(ch);
	int d=-1;
	for(int i=0;i<N;i++)
	{
		if(ch[i]=='0'&&ch[(i+1)%N]=='1'){
			d=i;
			break;
		}
	}
	int ans=1<<29;
	int c=0;
	for(int i=d+1;i<N;i++)
	{
		tmp[c]=ch[i];
		c++;
	}
	for(int i=0;i<d;i++)
	{
		tmp[c]=ch[i];
		c++;
	}
	ans=min(ans,solve());
	c=0;
	for(int i=d;i>=0;i--)
	{
		tmp[c]=ch[i];
		c++;
	}
	for(int i=N-1;i>=d+2;i--)
	{
		tmp[c]=ch[i];
		c++;
	}
	ans=min(ans,solve());
	printf("%d\n",ans);
	return 0;
}