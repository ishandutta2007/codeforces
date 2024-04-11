#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int> s[1007];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x;
		s[i].first=0;
		for (int j=1;j<=4;j++)
		{
			scanf("%d",&x);
			s[i].first-=x;
		}
		s[i].second=i;
	}
	sort(s+1,s+n+1);
	int ans=1;
	for (int i=1;i<=n;i++)
		if (s[i].second==1) ans=i;
	printf("%d\n",ans);
	return 0;
}