#include <stdio.h>
#include <deque>
using namespace std;
#define ll long long
const int N=150050;
const int M=2;
const ll inf=9e18;
ll dp[M][N];
int a[N],b[N],t[N];
deque<int> q;
int min(int a, int b){ return a>b?b:a;}
ll min(ll a, ll b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
int abs(int x){ return x>0?x:-x;}
int main()
{
	int n,m,k,i,j;
	scanf("%i %i %i",&n,&m,&k);
	for(i=1;i<=m;i++) scanf("%i %i %i",&a[i],&b[i],&t[i]);
	int c=0,p=1;
	for(j=1;j<=m;j++)
	{
		int time=t[j]-t[j-1];
		int sz=min((ll)n,(ll)time*k);
		for(i=1;i<=min(sz,n);i++)
		{
			while(!q.empty() && dp[p][q.back()]<=dp[p][i]) q.pop_back();
			q.push_back(i);
		}
		for(i=1;i<=n;i++)
		{
			if(i+sz<=n)
			{
				while(!q.empty() && dp[p][q.back()]<dp[p][i+sz]) q.pop_back();
				q.push_back(i+sz);
			}
			dp[c][i]=dp[p][q.front()]+b[j]-abs(a[j]-i);
			while(!q.empty() && q.front()<=i-sz) q.pop_front();
		}
		while(!q.empty()) q.pop_back();
		c^=1;
		p^=1;
	}
	ll sol=-inf;
	for(i=1;i<=n;i++) sol=max(sol,dp[p][i]);
	printf("%lld\n",sol);
	return 0;
}