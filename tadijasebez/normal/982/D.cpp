#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
#define mp make_pair
const int N=100050;
int id[N],a[N];
set<pair<int,int> > ord;
set<pair<int,int> >::iterator it;
int sz[N];
bool comp(int i, int j){ return a[i]<a[j];}
int loc,sol;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id[i]=i;
	sort(id+1,id+1+n,comp);
	for(i=1;i<=n;i++)
	{
		int j=id[i],l=j,r=j;
		it=ord.upper_bound(mp(j,0));
		if(it!=ord.end() && it->first==j+1)
		{
			r=it->second;
			sz[it->second-it->first+1]--;
			ord.erase(it);
		}
		it=ord.upper_bound(mp(j,0));
		if(it!=ord.begin())
		{
			it--;
			if(it->second==j-1)
			{
				l=it->first;
				sz[it->second-it->first+1]--;
				ord.erase(it);
			}
		}
		sz[r-l+1]++;
		ord.insert(mp(l,r));
		if(sz[r-l+1]==ord.size())
		{
			if(ord.size()>loc)
			{
				loc=ord.size();
				sol=a[j]+1;
			}
		}
	}
	printf("%i\n",sol);
	return 0;
}