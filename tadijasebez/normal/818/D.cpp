#include <stdio.h>
#include <set>
using namespace std;
#define mp make_pair
set< pair<int,int> > Set;
set< pair<int,int> >::iterator it;
const int N=1000500;
int n,b,C[N];
void Err()
{
	it=Set.lower_bound(mp(C[b],0));
	Set.erase(Set.begin(),it);
}
int main()
{
	int i,x;
	scanf("%i %i",&n,&b);
	for(i=1;i<=N;i++) if(i!=b) Set.insert(mp(0,i));
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		if(x!=b && Set.count(mp(C[x],x)))
		{
			Set.erase(mp(C[x],x));
			C[x]++;
			Set.insert(mp(C[x],x));
		}
		if(x==b)
		{
			C[x]++;
			Err();
		}
	}
	if(Set.empty()) printf("-1\n");
	else printf("%i\n",Set.begin()->second);
	return 0;
}