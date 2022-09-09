#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
set< pair<int,int> > Set[3];
set< pair<int,int> >::iterator it;
vector<int> sol;
int main()
{
	int n,i,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&x),Set[x%3].insert(make_pair(x,i));
	int p=-1;
	for(i=0;i<n;i++)
	{
		int j=i%3;
		if(Set[j].empty()) return printf("Impossible\n"),0;
		it=Set[j].lower_bound(make_pair(p,0));
		if(it==Set[j].end()) it--;
		if(it->first>p+1)
		{
			if(it==Set[j].begin()) return printf("Impossible\n"),0;
			it--;
		}
		sol.push_back(it->second);
		p=it->first;
		Set[j].erase(*it);
	}
	printf("Possible\n");
	for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
	printf("\n");
	return 0;
}