#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=200050;
#define ll long long
ll max(ll a, ll b){ return a>b?a:b;}
vector<int> E[N];
ll dp[N][2];
int a[N];
void DFS(int u)
{
	vector<ll> tmp;
	ll sum=0;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		DFS(v);
		tmp.push_back(dp[v][1]-dp[v][0]);
		sum+=dp[v][0];
	}
	if(tmp.empty())
	{
		dp[u][0]=0;
		dp[u][1]=a[u];
		return;
	}
	sort(tmp.begin(),tmp.end());
	reverse(tmp.begin(),tmp.end());

	ll sum1=0;
	int j;
	for(j=1;j<tmp.size();j+=2)
	{
		if(tmp[j]+tmp[j-1]<0) break;
		sum1+=tmp[j]+tmp[j-1];
	}
	dp[u][1]=sum+sum1+a[u];
	dp[u][0]=sum+sum1;

	ll sum2=0;
	sum2+=tmp[0];
	for(j=2;j<tmp.size();j+=2)
	{
		if(tmp[j]+tmp[j-1]<0) break;
		sum2+=tmp[j]+tmp[j-1];
	}
	dp[u][1]=max(dp[u][1],sum+sum2);
}
int main()
{
	int n,u,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&u,&a[i]);
		if(u>0) E[u].push_back(i);
	}
	DFS(1);
	printf("%lld\n",dp[1][1]);
	return 0;
}