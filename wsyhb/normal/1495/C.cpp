#include<bits/stdc++.h>
using namespace std;
const int max_n=500+5;
char Map[max_n][max_n]; 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			scanf("%s",Map[i]+1);
		for(int i=1;i<=n;i+=3)
		{
			for(int j=1;j<=m;++j)
				Map[i][j]='X';
			if(i+2<n)
			{
				bool flag=false;
				for(int j=1;j<=m;++j)
				{
					if(Map[i+1][j]=='X'||Map[i+2][j]=='X')
					{
						Map[i+1][j]=Map[i+2][j]='X';
						flag=true;
						break;
					}
				}
				if(!flag)
					Map[i+1][1]=Map[i+2][1]='X';
			}
			else if(i+2==n)
			{
				for(int j=1;j<=m;++j)
				{
					if(Map[i+1][j]=='X'||Map[i+2][j]=='X')
						Map[i+1][j]=Map[i+2][j]='X';
				}
			}
		}
		for(int i=1;i<=n;++i)
			printf("%s\n",Map[i]+1);
	}
    return 0;
}