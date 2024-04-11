#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,v[N],c[N],l[N],r[N],p[N],dp[N],zh[N],ansv;
vector<int>x[N],ans;
void solve(int m)
{
	for(int i=0;i<x[m].size();i++)
	{
		int k=x[m][i];
		p[l[k]]=p[l[k]+c[k]]=dp[l[k]]=dp[l[k]+c[k]]=0;
	}
	for(int i=0;i<x[m].size();i++)
	{
		int k=x[m][i];
		if(l[k]&&!dp[l[k]])
			continue;
		p[i]=zh[l[k]];
		if(dp[l[k]+c[k]]<dp[l[k]]+v[k])
		{
			dp[l[k]+c[k]]=dp[l[k]]+v[k];
			zh[l[k]+c[k]]=i;
		}
	}
	if(dp[m]>ansv)
	{
		ansv=dp[m];
		ans.clear();
		int z=zh[m];
		while(1)
		{
			ans.push_back(x[m][z]);
			if(l[x[m][z]]==0)
				break;
			z=p[z];
		}
		reverse(ans.begin(),ans.end());
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&v[i],&c[i],&l[i],&r[i]);
		x[l[i]+r[i]+c[i]].push_back(i);
	}
	for(int i=1;i<=300000;i++)
		if(x[i].size())
			solve(i);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
	return 0;
}