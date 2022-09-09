#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=300050;
const int S=550;
ll dp[N],w[N],n;
ll Recur(int a, int b)
{
	if(a>n) return 0;
	return Recur(a+b,b)+w[a];
}
ll DP(int a, int b)
{
	if(a>n) return 0;
	if(!dp[a]) return dp[a]=DP(a+b,b)+w[a];
	return dp[a];
}
void Init(){ for(int i=1;i<=n;i++) dp[i]=0;}
vector<pair<int,int> > Q[S];
ll sol[N];
int main()
{
	int i,j,q,a,b;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&w[i]);
	scanf("%i",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%i %i",&a,&b);
		if(b<S)
		{
			Q[b].pb(mp(a,i));
		}
		else sol[i]=Recur(a,b);
	}
	for(i=1;i<S;i++)
	{
		Init();
		for(j=0;j<Q[i].size();j++)
		{
			sol[Q[i][j].second]=DP(Q[i][j].first,i);
		}
	}
	for(i=1;i<=q;i++) printf("%lld\n",sol[i]);
	return 0;
}