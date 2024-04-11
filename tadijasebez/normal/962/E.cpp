#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
vector<int> Green,Red,Blue;
ll sol;
int main()
{
	int n,i,j,x,y;char t;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %c",&x,&t);
		if(t=='B') Blue.pb(x);
		if(t=='R') Red.pb(x);
		if(t=='P') Green.pb(x);
	}
	sort(Blue.begin(),Blue.end());
	sort(Green.begin(),Green.end());
	sort(Red.begin(),Red.end());
	if(Green.empty())
	{
		if(Blue.size()) sol+=Blue.back()-Blue.front();
		if(Red.size()) sol+=Red.back()-Red.front();
		printf("%lld\n",sol);
		return 0;
	}
	if(Red.size() && Red.front()<Green.front()) sol+=Green.front()-Red.front();
	if(Red.size() && Red.back()>Green.back()) sol+=Red.back()-Green.back();
	if(Blue.size() && Blue.front()<Green.front()) sol+=Green.front()-Blue.front();
	if(Blue.size() && Blue.back()>Green.back()) sol+=Blue.back()-Green.back();
	for(i=0;i<(signed)Green.size()-1;i++)
	{
		x=Green[i];y=Green[i+1];
		int l=lower_bound(Blue.begin(),Blue.end(),x)-Blue.begin();
		int r=upper_bound(Blue.begin(),Blue.end(),y)-Blue.begin();
		bool lf=0,rf=0;
		int lc=0,rc=0;
		if(l<r)
		{
			lf=1;
			lc=max(lc,Blue[l]-x);
			for(j=l;j<r-1;j++) lc=max(lc,Blue[j+1]-Blue[j]);
			lc=max(lc,y-Blue[r-1]);
		}
		l=lower_bound(Red.begin(),Red.end(),x)-Red.begin();
		r=upper_bound(Red.begin(),Red.end(),y)-Red.begin();
		if(l<r)
		{
			rf=1;
			rc=max(rc,Red[l]-x);
			for(j=l;j<r-1;j++) rc=max(rc,Red[j+1]-Red[j]);
			rc=max(rc,y-Red[r-1]);
		}
		if(lf && rf)
		{
			sol+=min((ll)(y-x)*2,(ll)(y-x)*3-lc-rc);
		}
		else if(lf) sol+=(ll)(y-x)*2-lc;
		else if(rf) sol+=(ll)(y-x)*2-rc;
		else sol+=y-x;
	}
	printf("%lld\n",sol);
	return 0;
}