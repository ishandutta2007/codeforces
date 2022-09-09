#include <stdio.h>
#include <set>
#include <queue>
using namespace std;
#define ll long long
struct Query
{
	ll time;
	int type,index;
	Query(){}
	Query(ll a, int b, int c){ time=a,type=b,index=c;}
	inline bool operator < (const Query &b) const
	{
		if(time==b.time && type==b.type) return index<b.index;
		if(time==b.time) return type<b.type;
		return time<b.time;
	}
};
set<Query> Set;
set<Query>::iterator it;
queue<int> q;
const int N=500050;
int k,m,n,L[N];
ll sol[N];
int main()
{
	int i,t;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&t,&L[i]);
		Set.insert(Query(t,2,i));
	}
	for(it=Set.begin();it!=Set.end();it++)
	{
		ll time=it->time;
		int type=it->type;
		int j=it->index;
		if(type==2)
		{
			q.push(j);
		}
		else
		{
			sol[j]=time;
			k--;
		}
		while(!q.empty() && k<m)
		{
			int a=q.front();
			q.pop();
			Set.insert(Query(time+L[a],1,a));
			k++;
		}
	}
	for(i=1;i<=n;i++) printf("%lld\n",sol[i]);
	return 0;
}