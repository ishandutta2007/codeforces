#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[210][60],i,j,le;
char ch[1200];
int n,ps,pc,dr,id;
int main()
{
	while(~scanf("%d%d%d",&n,&ps,&pc))
	{
		scanf("%s",ch);scanf("%s",ch);
		if(ch[0]=='h')dr=-1;
		else dr=1;
		scanf("%s",ch);
		le=strlen(ch);
		memset(dp,0,sizeof(dp));
		dp[0][ps]=1;
		bool can=true;
		for(i=1;i<=le;i++)
		{
			if(ch[i-1]=='0')
			{
				for(j=1;j<=n;j++)
				{
					if(j!=pc)
					{
						if(dp[i-1][j])dp[i][j]=1;
						if(j>1&&dp[i-1][j-1])dp[i][j]=1;
						if(j<n&&dp[i-1][j+1])dp[i][j]=1;
					}
			//		printf("%d %d %d\n",i,j,dp[i][j]);
				}
				if(pc+dr>=1&&pc+dr<=n)pc+=dr;
				else {dr=-dr;pc+=dr;}
				dp[i][pc]=0;
			//	printf("%d\n",pc);
			}
			else
			{				
				if(pc+dr>=1&&pc+dr<=n)pc+=dr;
				else {dr=-dr;pc+=dr;}
				for(j=1;j<=n;j++)dp[i][j]=1;
				dp[i][pc]=0;
			}
			bool fg=false;
			for(j=1;j<=n;j++)
			if(dp[i][j])fg=true;
			if(!fg)
			{
				can=false;
				id=i;break;
			}
		}
		if(can)puts("Stowaway");
		else printf("Controller %d\n",id);
	}
}