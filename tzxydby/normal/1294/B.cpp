#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>a;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		a.clear();
		a.emplace_back(0,0);
		for(int i=1;i<=n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a.emplace_back(x,y);
		}
		sort(a.begin(),a.end());
		int flag=1;
		for(int i=1;i<=n;i++)
			if(a[i].second<a[i-1].second)
				flag=0;
		if(flag)
		{
			puts("YES");
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=a[i].first-a[i-1].first;j++)
					printf("R");
				for(int j=1;j<=a[i].second-a[i-1].second;j++)
					printf("U");
			}
			puts("");
		}
		else
			puts("NO");
	}
	return 0;
}