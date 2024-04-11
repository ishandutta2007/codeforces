#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%i",&n);
	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++) scanf("%i",&a[i].first),a[i].second=i+1;
	mt19937 rng(time(0));
	vector<int> ans(n+1,0);
	while(clock()<0.4*CLOCKS_PER_SEC)
	{
		shuffle(a.begin(),a.end(),rng);
		int g=a[0].first;
		ans[a[0].second]=1;
		for(int i=1;i<a.size();i++)
		{
			int ng=__gcd(g,a[i].first);
			if(ng!=g)
			{
				ans[a[i].second]=1;
				g=ng;
			}
			else ans[a[i].second]=2;
		}
		if(g!=1) continue;
		g=0;
		for(int i=0;i<a.size();i++)
		{
			if(ans[a[i].second]==2)
			{
				if(g==0) g=a[i].first;
				else g=__gcd(g,a[i].first);
			}
		}
		if(g==1)
		{
			printf("YES\n");
			for(int i=1;i<=n;i++) printf("%i ",ans[i]);
			printf("\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}