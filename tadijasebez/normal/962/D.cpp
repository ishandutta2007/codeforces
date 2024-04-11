#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
set<pair<ll,int> > pq;
set<pair<ll,int> >::iterator it1,it2;
vector<pair<int,ll> > sol;
const int N=150050;
int a[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		pq.insert(mp(a[i],i));
	}
	while(pq.size())
	{
		if(pq.size()>1)
		{
			it1=pq.begin();it2=it1;it2++;
			if(it2->first!=it1->first)
			{
				sol.pb(mp(it1->second,it1->first));
				pq.erase(pq.begin());
			}
			else
			{
				ll x=it2->first;
				int id=it2->second;
				pq.erase(pq.begin());
				pq.erase(pq.begin());
				pq.insert(mp(x*2,id));
			}
		}
		else
		{
			sol.pb(mp(pq.begin()->second,pq.begin()->first));
			pq.clear();
		}
	}
	sort(sol.begin(),sol.end());
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%lld ",sol[i].second);
	printf("\n");
	return 0;
}