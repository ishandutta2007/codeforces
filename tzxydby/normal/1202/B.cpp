#include<bits/stdc++.h>
using namespace std;
const int N=2000005,inf=0x3f3f3f3f;
char s[N];
int dis[10][10];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int x=0;x<10;x++)
	{
		for(int y=0;y<10;y++)
		{
			memset(dis,inf,sizeof(dis));
			for(int k=0;k<10;k++)
				dis[k][(k+x)%10]=1,dis[k][(k+y)%10]=1;
			for(int k=0;k<10;k++)
				for(int i=0;i<10;i++)
					for(int j=0;j<10;j++)
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			int ans=0;
			for(int i=2;i<=n;i++)
			{
				int u=s[i-1]-'0',v=s[i]-'0';
				if(dis[u][v]==inf)
				{
					ans=inf;
					break;
				}
				ans+=dis[u][v];
			}
			printf("%d ",(ans==inf?-1:ans-n+1));
		}
		puts("");
	}
	return 0;
}