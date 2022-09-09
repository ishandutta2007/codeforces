#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
int main()
{
	int t;
	scanf("%i",&t);
	while(t--)
	{
		int n;
		scanf("%i",&n);
		vector<pair<pair<int,int>,int>> work(n);
		vector<int> sol(n);
		for(int i=0;i<n;i++) scanf("%i %i",&work[i].first.first,&work[i].first.second),work[i].second=i;
		bool ok=0;
		sort(work.begin(),work.end());
		int mx=-(1e9+7);
		for(int i=0;i<n;i++)
		{
			if(i!=0 && mx<work[i].first.first)
			{
				for(int j=0;j<i;j++) sol[work[j].second]=1;
				for(int j=i;j<n;j++) sol[work[j].second]=2;
				ok=1;
				break;
			}
			mx=max(mx,work[i].first.second);
		}
		if(!ok) printf("-1\n");
		else
		{
			for(int i=0;i<n;i++) printf("%i ",sol[i]);
			printf("\n");
		}
	}
	return 0;
}