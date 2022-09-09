#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
const int N=200050;
set< pair<int,int> > Set;
set< pair<int,int> >::iterator it,it1;
vector<int> Bids[N];
pair<int,int> Query()
{
	if(Set.empty()) return mp(0,0);
	if(Set.size()==1) return mp(Set.begin()->second,Bids[Set.begin()->second][0]);
	it=Set.end();it--;
	it1=it;it1--;
	int j=it->second;
	int i=lower_bound(Bids[j].begin(),Bids[j].end(),it1->first)-Bids[j].begin();
	return mp(j,Bids[j][i]);
}
int a[N];
int main()
{
	int n,q,i,u,w,k;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&u,&w);
		Bids[u].push_back(w);
	}
	for(i=1;i<=n;i++)
	{
		if(!Bids[i].empty())
		{
			Set.insert(mp(*Bids[i].rbegin(),i));
		}
	}
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i",&k);
		for(i=1;i<=k;i++)
		{
			scanf("%i",&a[i]);
			if(Bids[a[i]].size())
				Set.erase(mp(*Bids[a[i]].rbegin(),a[i]));
		}
		pair<int,int> sol=Query();
		printf("%i %i\n",sol.first,sol.second);
		for(i=1;i<=k;i++)
		{
			if(Bids[a[i]].size())
				Set.insert(mp(*Bids[a[i]].rbegin(),a[i]));
		}
	}
	return 0;
}