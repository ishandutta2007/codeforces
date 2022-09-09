#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int N=100050;
const int S=317;
vector<int> Set[N];
bool was[N];
int both[S][N],a[N];
ll sum[N],lazy[N],b[N];
vector<int> Heavy;
int main()
{
	int n,m,q,i,j,sz,x,k;
	scanf("%i %i %i",&n,&m,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%i",&sz);
		while(sz--)
		{
			scanf("%i",&x);
			sum[i]+=a[x];
			Set[i].push_back(x);
		}
		if(Set[i].size()>=S) Heavy.push_back(i);
	}
	for(i=0;i<Heavy.size();i++)
	{
		int id=Heavy[i];
		for(j=0;j<Set[id].size();j++) was[Set[id][j]]=1;
		for(k=1;k<=m;k++) if(k!=id)
		{
			for(j=0;j<Set[k].size();j++) both[i][k]+=was[Set[k][j]];
		}
		for(j=0;j<Set[id].size();j++) was[Set[id][j]]=0;
	}
	char t;
	while(q--)
	{
		scanf("\n%c %i",&t,&x);
		if(t=='+')
		{
			scanf("%i",&k);
			if(Set[x].size()>=S)
			{
				sum[x]+=(ll)k*((signed)Set[x].size());
				//lazy[x]+=(ll)k*((signed)Set[x].size());
				lazy[x]+=k;
				for(i=0;i<Heavy.size();i++) sum[Heavy[i]]+=(ll)k*both[i][x];
			}
			else
			{
				for(j=0;j<Set[x].size();j++) b[Set[x][j]]+=k;
				for(i=0;i<Heavy.size();i++) sum[Heavy[i]]+=(ll)k*both[i][x];
			}
		}
		if(t=='?')
		{
			if(Set[x].size()>=S)
			{
				printf("%lld\n",sum[x]);
			}
			else
			{
				ll sol=sum[x];
				for(j=0;j<Set[x].size();j++) sol+=b[Set[x][j]];
				for(i=0;i<Heavy.size();i++) sol+=(ll)lazy[Heavy[i]]*both[i][x];
				printf("%lld\n",sol);
			}
		}
	}
	return 0;
}