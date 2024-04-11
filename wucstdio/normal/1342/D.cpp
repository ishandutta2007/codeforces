#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,k,m[200005],c[200005],sum[200005],cur[200005];
vector<int>res[200005];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&m[i]);
	for(int i=1;i<=k;i++)scanf("%d",&c[i]);
	sort(m+1,m+n+1);
	for(int i=1;i<=n;i++)sum[m[i]]++;
	for(int i=k;i>=1;i--)sum[i]+=sum[i+1];
	int ans=0;
	int now=1,j=n;
	for(int i=k;i>=1;i--)
	{
		if(c[i]!=c[i+1])now=1;
		while(j&&m[j]==i)
		{
			while(cur[now]==c[i])now++;
			res[now].push_back(m[j]);
			cur[now]++;
			ans=max(ans,now);
			j--;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
	{
		printf("%d ",(int)res[i].size());
		for(auto x:res[i])printf("%d ",x);
		printf("\n");
	}
	return 0;
}