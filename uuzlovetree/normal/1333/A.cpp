#include<bits/stdc++.h>
using namespace std;
int T,n,m; 
char Ans[105][105];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(Ans,0,sizeof(Ans));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)if((i+j)&1)Ans[i][j]='W';else Ans[i][j]='B';
		if((n*m)%2==0)
		{
			for(int i=1;i<=n;++i)
			{
				bool ys=0;
				for(int j=1;j<=m;++j)if(Ans[i][j]=='W')
				{
					Ans[i][j]='B';
					ys=1;
					break;
				}
				if(ys)break;
			}
		}
		for(int i=1;i<=n;++i)printf("%s\n",Ans[i]+1);
	}
}