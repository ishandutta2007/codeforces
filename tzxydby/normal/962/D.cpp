#include<bits/stdc++.h>
using namespace std;
map<long long,set<int>>a;
set<int>s;
vector<pair<int,long long>>ans;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		long long x;
		scanf("%I64d",&x);
		if(a.find(x)==a.end())
			a[x]=s;
		a[x].insert(i);
	}
	for(auto itr=a.begin();itr!=a.end();itr++)
	{
		while(itr->second.size()>=2)
		{
			int w1=*itr->second.begin();
			itr->second.erase(itr->second.begin());
			int w2=*itr->second.begin();
			itr->second.erase(itr->second.begin());
			a[2*itr->first].insert(w2);
		}
	}
	for(auto itr=a.begin();itr!=a.end();itr++)
	{
		while(itr->second.size())
		{
			ans.push_back(make_pair(*itr->second.begin(),itr->first));
			itr->second.erase(itr->second.begin());
		}
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%I64d ",ans[i].second);
	return 0;
}