#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>a[N];
int n,t,m[N],vis[N],ma[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int fl=1;
		for(int i=1;i<=n;i++)
			vis[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m[i]);
			a[i].resize(m[i]);
			ma[i]=0;
			for(int j=0;j<m[i];j++)
				scanf("%d",&a[i][j]);
			for(int j=0;j<m[i];j++)
			{
				if(!vis[a[i][j]])
				{
					ma[i]=a[i][j];
					vis[a[i][j]]=1;
					break;
				}
			}
		}
		for(int i=1;i<=n&&fl;i++)
		{
			if(ma[i])
				continue;
			for(int j=1;j<=n;j++)
			{
				if(!vis[j])
				{
					puts("IMPROVE");
					printf("%d %d\n",i,j);
					fl=0;
					break;
				}
			}
		}
		if(fl)
			puts("OPTIMAL");
	}
	return 0;
}