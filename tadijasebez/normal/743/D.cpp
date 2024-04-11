#include <stdio.h>
#include <vector>
using namespace std;
const int N=200050;
const long long inf=1000000000ll*N;
vector<int> Tree[N];
long long NodeSize[N];
int a[N];
void Calc(int cur, int prev)
{
	int i;
	NodeSize[cur]=a[cur];
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			Calc(v,cur);
			NodeSize[cur]+=NodeSize[v];
		}
	}
}
long long max(long long a, long long b){ return a>b?a:b;}
long long ans=-inf;
long long Solve(int cur, int prev)
{
	int i,j=0;
	long long best=-inf;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			long long tmp=Solve(v,cur);
			if(j) ans=max(ans,tmp+best);
			best=max(best,tmp);
			j++;
		}
	}
	return max(best,NodeSize[cur]);
}
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	Calc(1,0);
	Solve(1,0);
	if(ans==-inf) printf("Impossible\n");
	else printf("%lld\n",ans);
	return 0;
}