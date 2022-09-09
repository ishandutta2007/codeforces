#include <stdio.h>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=1005;
int w[N],sz[N],id[N];
bool comp(int a, int b){ return w[a]>w[b];}
set<pair<int,int> > Set;
set<pair<int,int> >::iterator it;
vector<pair<int,int> > sol;
int main()
{
	int n,k,i,x,sum=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i %i",&sz[i],&w[i]),id[i]=i;
	sort(id+1,id+1+n,comp);
	scanf("%i",&k);
	for(i=1;i<=k;i++) scanf("%i",&x),Set.insert(mp(x,i));
	for(i=1;i<=n;i++)
	{
		it=Set.lower_bound(mp(sz[id[i]],0));
		if(it!=Set.end())
		{
			sum+=w[id[i]];
			sol.pb(mp(id[i],it->second));
			Set.erase(it);
		}
	}
	printf("%i %i\n",sol.size(),sum);
	for(i=0;i<sol.size();i++) printf("%i %i\n",sol[i].first,sol[i].second);
	return 0;
}