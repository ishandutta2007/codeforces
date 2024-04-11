#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[1005][1005];
int main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int m,n=500000;
	cin>>m;
	int bl=sqrt(n);
	int opt,x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&opt,&x,&y);
		if(opt==2)
		{
			if(x<=bl)
			{
				printf("%d\n",ans[x][y]);
			}
			else
			{
				int ans=0;
				for(int i=y;i<=n;i+=x)
				{
					ans+=a[i];
				}
				printf("%d\n",ans);
			}
		}
		else
		{
			for(int i=1;i<=bl;i++)
			{
				ans[i][x%i]+=y;
			}
			a[x]+=y;
		}
	}
	return 0;
}