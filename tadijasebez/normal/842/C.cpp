#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=200050;
vector<int> divisors;
int cnt[N];
vector<int> Tree[N];
int ans[N],a[N];
int max(int a, int b){ return a>b?a:b;}
void DFS(int cur, int prev, int depth, int g)
{
	if(depth>1) g=__gcd(g,a[cur]);
	ans[cur]=g;
	int i;
	for(i=0;i<divisors.size();i++)
	{
		int d=divisors[i];
		if(a[cur]%d==0) cnt[d]++;
		if(cnt[d]>=depth-1) ans[cur]=max(ans[cur],d);
	}
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			DFS(v,cur,depth+1,g);
		}
	}
	for(i=0;i<divisors.size();i++)
	{
		int d=divisors[i];
		if(a[cur]%d==0) cnt[d]--;
	}
}
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&a[i]);
	for(i=0;i<n-1;i++)
	{
		scanf("%i %i",&u,&v);
		u--,v--;
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	for(i=1;i*i<=a[0];i++)
	{
		if(a[0]%i==0)
		{
			divisors.push_back(i);
			divisors.push_back(a[0]/i);
			if(i*i==a[0])
				divisors.pop_back();
		}
	}
	sort(divisors.begin(),divisors.end());
	DFS(0,0,1,0);
	for(i=0;i<n;i++) printf("%i ",ans[i]);
	return 0;
}