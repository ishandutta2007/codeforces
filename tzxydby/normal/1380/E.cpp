#include<bits/stdc++.h>
using namespace std;
const int N=200005;
set<int>s[N];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		s[x].insert(i);
	}
	int ans=n-1;
	for(int i=1;i<=m;i++)
		for(auto c:s[i])
			if(s[i].count(c-1))
				ans--;
	printf("%d\n",ans);
	for(int i=1;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(s[a].size()<s[b].size())
			s[a].swap(s[b]);
		for(auto c:s[b])
			ans-=s[a].count(c-1)+s[a].count(c+1);
		s[a].insert(s[b].begin(),s[b].end());
		s[b].clear();
		printf("%d\n",ans);
	}
	return 0;
}