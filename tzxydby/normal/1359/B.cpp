#include<bits/stdc++.h>
using namespace std;
const int N=105,M=1005;
char s[N][M];
int n,m,x,y,ans,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&x,&y);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		ans=0,y=min(y,2*x);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]=='.')
				{
					if(j<m&&s[i][j+1]=='.')
					{
						ans+=y;
						j++;
					}
					else
						ans+=x;
				}
			}
		}
		printf("%d\n",ans);
	}	
	return 0;
}