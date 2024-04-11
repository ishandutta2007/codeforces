#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=1e9+7;
set<pair<int,int> > Set;
set<pair<int,int> >::iterator it1,it2;
vector<int> sol;
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,l,r,i;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%i %i",&l,&r);
		it1=Set.lower_bound(mp(l,N));
		if(it1!=Set.begin())
		{
			it1--;
			if(it1->second<l) it1++;
		}
		if(it1!=Set.end()) l=min(l,it1->first);
		it2=Set.lower_bound(mp(r,N));
		if(it2!=Set.begin())
		{
			it2--;
			r=max(r,it2->second);
			it2++;
		}
		Set.erase(it1,it2);
		Set.insert(mp(l,r));
		sol.pb(Set.size());
	}
	for(i=0;i<sol.size();i++) printf("%i ",sol[i]);printf("\n");
	return 0;
}