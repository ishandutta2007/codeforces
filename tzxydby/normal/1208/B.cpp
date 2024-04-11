#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>>a;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x].push_back(i);
	}
	int ans=n;
	int flag=1;
	for(auto j:a)
		if(j.second.size()>1)
			flag=0;
	if(flag)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int r=i,flag=1;
		for(auto j:a)
		{
			if(j.second.size()==1) continue;
			int k=lower_bound(j.second.begin(),j.second.end(),i)-j.second.begin();
			if(k>1) flag=0;
			if(k==1) r=max(r,j.second.back());
			if(k==0) r=max(r,j.second[j.second.size()-2]);
		}
		if(flag)
			ans=min(ans,r-i+1);
	}
	printf("%d\n",ans);
	return 0;
}