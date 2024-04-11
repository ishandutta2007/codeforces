#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
vector<pair<int,int> >a;
int main()
{
	int n,k,l,r,sum=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		a.push_back(make_pair(l,-1));
		a.push_back(make_pair(r,1));
	}
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++)
	{
		if(sum<k&&sum-a[i].second>=k)
			ans.push_back(a[i].first);
		if(sum>=k&&sum-a[i].second<k)
			ans.push_back(a[i].first);
		sum-=a[i].second;
	}
	sum=0;
	for(int i=0;i<ans.size();i+=2)
	{
		if(ans[i+1]==ans[i+2])
			continue;
		sum++;
	}
	printf("%d\n",sum);
	for(int i=0;i<ans.size();i+=2)
	{
		if(ans[i+1]==ans[i+2])
		{
			ans[i+2]=ans[i];
			continue;
		}
		printf("%d %d\n",ans[i],ans[i+1]);
	}///
	return 0;
}