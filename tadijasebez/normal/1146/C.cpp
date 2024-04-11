#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
int ask(vector<int> x, vector<int> y)
{
	printf("%i %i ",x.size(),y.size());
	for(int i:x) printf("%i ",i);
	for(int i:y) printf("%i ",i);
	printf("\n");
	fflush(stdout);
	int b;
	scanf("%i",&b);
	return b;
}
int main()
{
	int n,i,t;
	scanf("%i",&t);
	while(t--)
	{
		scanf("%i",&n);
		int ans=-1;
		for(int j=0;j<9;j++)
		{
			vector<int> v[2];
			for(i=1;i<=n;i++)
			{
				v[(i>>j)&1].pb(i);
			}
			if(v[1].size() && v[0].size())
			{
				int d=ask(v[0],v[1]);
				ans=max(ans,d);
			}
		}
		printf("-1 %i\n",ans);
		fflush(stdout);
	}
	return 0;
}