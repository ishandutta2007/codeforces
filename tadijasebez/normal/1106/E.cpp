#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
const int M=205;
const ll inf=9e18;
ll dp[N][M];
vector<int> in[N],out[N];
int l[N],r[N],d[N],w[N];
int jmp[N],cost[N];
int main()
{
	int n,m,k,i,j;
	scanf("%i %i %i",&n,&m,&k);
	for(i=1;i<=k;i++) scanf("%i %i %i %i",&l[i],&r[i],&d[i],&w[i]),in[l[i]].pb(i),out[r[i]].pb(i);
	for(i=2;i<=n+1;i++) for(j=0;j<=m;j++) dp[i][j]=inf;
	multiset<pair<int,int>> work;
	for(i=1;i<=n;i++)
	{
		for(int id:in[i]) work.insert(mp(w[id],d[id]));
		if(work.empty()) jmp[i]=i+1,cost[i]=0;
		else jmp[i]=work.rbegin()->second+1,cost[i]=work.rbegin()->first;
		for(int id:out[i]) work.erase(work.find(mp(w[id],d[id])));
		for(j=0;j<=m;j++)
		{
			dp[jmp[i]][j]=min(dp[jmp[i]][j],dp[i][j]+cost[i]);
			dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
		}
	}
	printf("%lld\n",dp[n+1][m]);
	return 0;
}