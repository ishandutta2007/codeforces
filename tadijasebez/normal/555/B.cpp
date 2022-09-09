#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const int N=200050;
struct Interval
{
	ll l,r,i;
	Interval(){}
	Interval(ll a, ll b, ll c){ l=a,r=b,i=c;}
	inline bool operator < (const Interval &b) const
	{
		if(r==b.r) return i<b.i;
		return r<b.r;
	}
};
set<Interval> intervals;
set<Interval>::iterator it;
struct Query
{
	ll l,t,i;
	Query(){}
	Query(ll a, ll b, ll c){ l=a,t=b,i=c;}
	inline bool operator < (const Query &b) const
	{
		if(l==b.l) return t<b.t;
		return l<b.l;
	}
};
vector<Query> events;
ll L[N],R[N],X[N];
int ans[N];
int main()
{
	int n,m,i;
	ll b,e,l,r;
	scanf("%i %i",&n,&m);
	scanf("%lld %lld",&b,&e);
	for(i=1;i<n;i++)
	{
		scanf("%lld %lld",&l,&r);
		L[i]=l-e,R[i]=r-b;
		events.push_back(Query(L[i],1,i));
		events.push_back(Query(R[i],3,i));
		b=l,e=r;
	}
	for(i=1;i<=m;i++) scanf("%lld",&X[i]),events.push_back(Query(X[i],2,i));
	sort(events.begin(),events.end());
	for(i=0;i<events.size();i++)
	{
		if(events[i].t==1)
		{
			int j=events[i].i;
			intervals.insert(Interval(L[j],R[j],j));
		}
		else if(events[i].t==3)
		{
			int j=events[i].i;
			intervals.erase(Interval(L[j],R[j],j));
		}
		else
		{
			int j=events[i].i;
			if(!intervals.empty())
			{
				it=intervals.begin();
				//if(R[it->i]<X[j]) return printf("No\n"),0;
				ans[it->i]=j;
				intervals.erase(it);
			}
		}
	}
	//if(!intervals.empty()) return printf("No\n"),0;
	for(i=1;i<n;i++) if(ans[i]==0) return printf("No\n"),0;
	printf("Yes\n");
	for(i=1;i<n;i++) printf("%i ",ans[i]);
	printf("\n");
	return 0;
}