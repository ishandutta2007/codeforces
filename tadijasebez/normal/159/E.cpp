#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int N=100050;
#define pb push_back
#define mp make_pair
#define ll long long
set<pair<ll,int> ,greater<pair<ll,int> > > Set;
set<pair<ll,int> ,greater<pair<ll,int> > >::iterator it;
vector<int> ids[N];
vector<int> id;
vector<pair<ll,int> > lzy,bck;
int c[N],h[N];
bool comp(int a, int b){ return h[a]>h[b];}
ll sol;
int id1,id2,sz1,sz2;
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i %i",&c[i],&h[i]),id.pb(c[i]);
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	for(i=1;i<=n;i++) ids[lower_bound(id.begin(),id.end(),c[i])-id.begin()].pb(i);
	for(i=0;i<id.size();i++) Set.insert(mp(0,i));
	for(i=0;i<id.size();i++) sort(ids[i].begin(),ids[i].end(),comp);
	for(i=1;i<N && !Set.empty();i++)
	{
		for(it=Set.begin();it!=Set.end();it++)
		{
			int x=it->second;
			ll val=it->first;
			bck.pb(*it);
			if(ids[x].size()>=i)
			{
				lzy.pb(mp(val+h[ids[x][i-1]],x));
			}
		}
		Set.clear();
		for(j=0;j<lzy.size();j++) Set.insert(lzy[j]);
		lzy.clear();
		if(Set.empty()) break;
		if(Set.size()>1)
		{
			ll ans=Set.begin()->first;
			it=Set.begin();it++;
			ans+=it->first;
			if(sol<ans)
			{
				sol=ans;
				id1=Set.begin()->second;
				id2=it->second;
				sz1=i;
				sz2=i;
			}
		}
		for(j=0;j<bck.size();j++)
		{
			if(bck[j].first==0) continue;
			int index=bck[j].second;
			if(Set.begin()->second==index)
			{
				if(Set.size()>1)
				{
					it=Set.begin();it++;
					ll ans=it->first;
					ans+=bck[j].first;
					if(ans>sol)
					{
						sol=ans;
						id1=it->second;
						id2=index;
						sz1=i;
						sz2=i-1;
					}
				}
			}
			else
			{
				ll ans=Set.begin()->first;
				ans+=bck[j].first;
				if(ans>sol)
				{
					sol=ans;
					id1=Set.begin()->second;
					id2=index;
					sz1=i;
					sz2=i-1;
				}
			}
		}
		bck.clear();
	}
	printf("%lld\n",sol);
	printf("%i\n",sz1+sz2);
	for(i=0;i<sz1+sz2;i++)
	{
		if(i&1) printf("%i ",ids[id2][i/2]);
		else printf("%i ",ids[id1][i/2]);
	}
	return 0;
}