#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int t,n,a[200005],sum[200005][205];
vector<int>p[205];
int ask(int l,int r)
{
	int ans=0;
	for(int i=1;i<=200;i++)ans=max(ans,sum[r][i]-sum[l-1][i]);
	return ans;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=200;i++)p[i].clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			p[a[i]].push_back(i);
			for(int j=1;j<=200;j++)sum[i][j]=sum[i-1][j];
			sum[i][a[i]]++;
		}
		int ans=0;
		for(int i=1;i<=200;i++)
		{
			if(p[i].empty())continue;
			ans=max(ans,(int)p[i].size());
			int l=0,r=(int)p[i].size()-1,num=2;
			while(l<r)
			{
				ans=max(ans,num+ask(p[i][l]+1,p[i][r]-1));
				l++,r--;
				num+=2;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}