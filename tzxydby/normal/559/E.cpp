#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,dp[N][N][2],ans;
pair<int,int>a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].first,&a[i].second);
	sort(a+1,a+n+1);
	a[0].first=-1e9;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int p=0;p<2;p++)
			{
				ans=max(ans,dp[i][j][p]);
				int r=a[j].first+p*a[j].second,m=-1e9,nj,np;
				for(int k=i+1;k<=n;k++)
				{
					for(int q=0;q<2;q++)
					{
						int t=a[k].first+q*a[k].second;
						if(t>m)
							m=t,nj=k,np=q;
						dp[k][nj][np]=max(dp[k][nj][np],dp[i][j][p]+min(a[k].second,t-r)+m-t);
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}