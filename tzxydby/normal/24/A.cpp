#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>e[105];
int main()
{
	int n,a,b,c,sum=0,cur=1,tmp=0,pre=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		e[a].push_back(make_pair(b,0));
		e[b].push_back(make_pair(a,c));
		sum+=c; 
	}
	for(int i=1;i<=n;i++)
	{
		int city,cost;
		for(int j=0;j<2;j++)
		{
			city=e[cur][j].first,cost=e[cur][j].second;
			if(city!=pre)
				break;
		}
		tmp+=cost;
		pre=cur;
		cur=city;
	}
	printf("%d\n",min(tmp,sum-tmp));
	return 0;
}