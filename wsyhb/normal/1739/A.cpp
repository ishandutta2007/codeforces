#include<bits/stdc++.h>
using namespace std;
const int dx[8]={-1,-2,-2,-1,1,2,2,1};
const int dy[8]={-2,-1,1,2,-2,-1,1,2};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int ans1=1,ans2=1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				bool ok=true;
				for(int k=0;k<8;++k)
				{
					int x=i+dx[k],y=j+dy[k];
					if(x>=1&&x<=n&&y>=1&&y<=m)
					{
						ok=false;
						break;
					}
				}
				if(ok)
					ans1=i,ans2=j;
			}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}