#include <cstdio> //fast io
#include <vector>
#include <utility>

typedef long long int ll;
typedef std::pair<ll, ll> ii;

const int ms=200100;
const ll INF=0x3f3f3f3f3f3f3f3fLL;

int n;
int p[ms];
std::vector<int> edges[ms];

bool visit[ms];
ll highest[ms], val[ms];
int par[ms];

ll dfs(int on, int parent)
{
	if(visit[on])
		return 0;
	visit[on]=true;
	par[on]=parent;
	ll &ans=highest[on];
	ans=-INF;
	ll &sum=val[on];
	sum=p[on];
	for(int i=0;i<edges[on].size();i++)
	{
		int to=edges[on][i];
		if(to==parent)
			continue;
		dfs(to, on);
		sum+=val[to];
		ans=std::max(ans, highest[to]);
	}
	ans=std::max(ans, sum);
	//printf("highest of %i is %lli, sum is %lli\n",on,highest[on],val[on]);
	return ans;
}

bool visit2[ms];
ll memo[ms];

ii fix(ii a)
{
	if(a.first<a.second)
		return ii(a.second, a.first);
	return a;
}

ii merge(ii a, ii b)
{
	if(b.first>a.second)
		a=fix(ii(a.first, b.first));
	if(b.second>a.second)
		a=fix(ii(a.first, b.second));
	return a;
}


ll pd(int on)
{
	if(visit2[on])
		return memo[on];
	visit2[on]=true;
	ii ans=ii(-INF, -INF);
	ll total_ans=-INF;
	for(int i=0;i<edges[on].size();i++)
	{
		int to=edges[on][i];
		if(to==par[on])
			continue;
		pd(to);
	}
	for(int i=0;i<edges[on].size();i++)
	{
		int to=edges[on][i];
		if(to==par[on])
			continue;
		ans=merge(ans, ii(highest[to], -INF));
		total_ans=std::max(total_ans, pd(to));
		//printf("%lli %lli\n",ans.first,ans.second);
	}
	if(ans.second!=-INF)
		total_ans=std::max(total_ans, ans.first+ans.second);
	//printf("on %i returning %lli\n",on,total_ans);
	return memo[on]=total_ans;
}


int main()
{
	scanf("%i",&n);
	for(int i=0;i<n;i++)
		scanf("%i",p+i);
	for(int i=0;i<n-1;i++)
	{
		int t1,t2;
		scanf("%i %i",&t1,&t2);
		t1--;t2--;
		edges[t1].push_back(t2);
		edges[t2].push_back(t1);
	}
	dfs(0, -1);
	if(pd(0)==-INF)
		printf("Impossible\n");
	else
		printf("%lli\n",pd(0));

}