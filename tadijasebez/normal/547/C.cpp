#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
const int N=500050;
const int S=710;
int cnt[N];
vector<int> Div[N],Prime;
bool sieve[S];
void FindPrimes()
{
	int i,j;
	for(i=2;i<S;i++)
	{
		if(!sieve[i])
		{
			Prime.pb(i);
			for(j=i;j<S;j+=i) sieve[j]=1;
		}
	}
}
vector< pair<int,int> > tmp[N];
void Make(int i, int j, int c, int x)
{
	if(j>=Div[i].size())
	{
		tmp[i].pb(mp(x,c));
	}
	else
	{
		Make(i,j+1,c,x);
		Make(i,j+1,c+1,x*Div[i][j]);
	}
}
bool in[N];
int main()
{
	FindPrimes();
	int n,q,i,x,j;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		for(j=0;j<Prime.size();j++)
		{
			if(x%Prime[j]) continue;
			Div[i].pb(Prime[j]);
			while(!(x%Prime[j])) x/=Prime[j];
		}
		if(x>1) Div[i].pb(x);
		Make(i,0,0,1);
	}
	ll sol=0;
	while(q--)
	{
		scanf("%i",&i);
		if(in[i])
		{
			for(j=0;j<tmp[i].size();j++) cnt[tmp[i][j].first]--;
			for(j=0;j<tmp[i].size();j++) sol+=(tmp[i][j].second&1?1:-1)*cnt[tmp[i][j].first];
			in[i]=0;
		}
		else
		{
			for(j=0;j<tmp[i].size();j++) sol-=(tmp[i][j].second&1?1:-1)*cnt[tmp[i][j].first];
			for(j=0;j<tmp[i].size();j++) cnt[tmp[i][j].first]++;
			in[i]=1;
		}
		printf("%lld\n",sol);
	}
	return 0;
}