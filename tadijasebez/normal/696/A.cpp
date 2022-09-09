#include <stdio.h>
#include <map>
using namespace std;
map<long long,long long> cost;
void Set(long long u, long long v, long long w)
{
	if(u==v) return;
	if(u<v)
	{
		cost[v]+=w;
		v>>=1;
		Set(u,v,w);
	}
	else
	{
		cost[u]+=w;
		u>>=1;
		Set(u,v,w);
	}
}
long long Get(long long u, long long v)
{
	if(u==v) return 0;
	if(u<v) return cost[v]+Get(u,v>>1);
	else return cost[u]+Get(u>>1,v);
}
int main()
{
	int q,t;
	long long u,v,w;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%lld %lld %lld",&u,&v,&w);
			Set(u,v,w);
		}
		else
		{
			scanf("%lld %lld",&u,&v);
			printf("%lld\n",Get(u,v));
		}
	}
	return 0;
}