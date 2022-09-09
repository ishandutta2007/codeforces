#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
int max(int a, int b){ return a>b?a:b;}
//int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=1000050;
const ll inf=1e18;
bool mark[N];
int cost[N];
vector<int> id;
int lo(int x){ return upper_bound(id.begin(),id.end(),x)-id.begin()-1;}
int main()
{
	int n,m,k,i,j,x;
	scanf("%i %i %i",&n,&m,&k);
	for(i=1;i<=m;i++) scanf("%i",&x),mark[x]=1;
	for(i=0;i<=n;i++) if(!mark[i]) id.pb(i);
	for(i=1;i<=k;i++) scanf("%i",&cost[i]);
	if(mark[0]) return printf("-1\n"),0;
	int o=1;
	for(i=0;i<id.size()-1;i++) o=max(o,id[i+1]-id[i]);
	if(o>k) return printf("-1\n"),0;
	ll sol=inf;
	for(j=o;j<=k;j++)
	{
		int cnt=0;
		for(i=0;i<id.size()-1;i=lo(id[i]+j)){ cnt++;}
		sol=min(sol,(ll)cnt*cost[j]);
	}
	printf("%lld\n",sol);
	return 0;
}