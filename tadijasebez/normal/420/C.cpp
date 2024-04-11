#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N=300050;;
int deg[N];
vector<pair<int,int> > edges;
map<pair<int,int> ,int> cnt;
struct RSQ
{
	int sum[1<<20];
	RSQ(){}
	void Set(int x, int val){ x+=1<<19;for(;x;x>>=1) sum[x]+=val;}
	int Get(int l, int r)
	{
		l+=1<<19;r+=1<<19;
		int ret=0;
		for(;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) ret+=sum[l++];
			if(r%2==0) ret+=sum[r--];
		}
		return ret;
	}
} Tree;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,p,u,v,i;
	scanf("%i %i",&n,&p);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&u,&v);
		if(u>v) u^=v,v^=u,u^=v;
		edges.pb(mp(u,v));
		cnt[mp(u,v)]++;
		deg[u]++;deg[v]++;
	}
	for(i=1;i<=n;i++) Tree.Set(deg[i],1);
	ll sol=0;
	for(i=1;i<=n;i++)
	{
		Tree.Set(deg[i],-1);
		sol+=Tree.Get(max(p-deg[i],0),N);
		Tree.Set(deg[i],1);
	}
	sort(edges.begin(),edges.end());
	edges.erase(unique(edges.begin(),edges.end()),edges.end());
	for(i=0;i<edges.size();i++)
	{
		u=edges[i].first;
		v=edges[i].second;
		if(deg[u]+deg[v]>=p)
		{
			if(deg[u]+deg[v]-cnt[edges[i]]<p) sol-=2;
		}
	}
	printf("%lld\n",sol/2);
	return 0;
}