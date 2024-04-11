#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
const int mod=1e9+7;
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
const int N=200050;
int F[N],I[N];
int Calc(int n, int k){ return (ll)F[n]*I[n-k]%mod*I[k]%mod;}
set<int> ord;
vector<pair<int,int> > events;
int main()
{
	int n,k,i,l,r;
	scanf("%i %i",&n,&k);
	F[0]=1;
	for(i=1;i<=n;i++) F[i]=(ll)F[i-1]*i%mod;
	I[n]=pow(F[n],mod-2);
	for(i=n-1;~i;i--) I[i]=(ll)I[i+1]*(i+1)%mod;
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&l,&r);r++;
		events.pb(mp(l,-i));
		events.pb(mp(r,i));
	}
	sort(events.begin(),events.end());
	int sol=0;
	int last=0,time;
	for(i=0;i<events.size();i++)
	{
		time=events[i].first-last;
		last=events[i].first;
		if(ord.size()>=k)
		{
			sol+=(ll)time*Calc(ord.size(),k)%mod;
			sol%=mod;
		}
		if(events[i].second<0) ord.insert(-events[i].second);
		else ord.erase(events[i].second);
	}
	printf("%i\n",sol);
	return 0;
}