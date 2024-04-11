#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
set<int>a,b,g;
set<pair<int,int>>s;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		s.insert(make_pair(0,x));
		b.insert(x);
	}
	while(a.size()<m)
	{
		int x=s.begin()->second,d=s.begin()->first;
		s.erase(s.begin());
		if(g.count(x))
			continue;
		g.insert(x);
		if(!b.count(x))
			a.insert(x),ans+=d;
		s.insert(make_pair(d+1,x-1));
		s.insert(make_pair(d+1,x+1));
	}
	printf("%lld\n",ans);
	for(auto i:a)
		printf("%d ",i);
	return 0;
}