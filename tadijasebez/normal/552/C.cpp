#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
vector<ll> fir,sec,tmp,f,s;
int main()
{
	ll w,n;int i,j;
	scanf("%lld %lld",&w,&n);
	if(w==2) return printf("YES\n"),0;
	ll a=1;
	for(i=0;a<=n;a*=w,i++)
	{
		if(i&1) f.pb(a);
		else s.pb(a);
	}
	if(i&1) f.pb(a);
	else s.pb(a);
	fir.pb(0);
	for(i=0;i<f.size();i++)
	{
		tmp.clear();
		for(j=0;j<fir.size();j++)
		{
			tmp.pb(fir[j]);
			tmp.pb(fir[j]-f[i]);
			tmp.pb(fir[j]+f[i]);
		}
		fir.clear();
		for(j=0;j<tmp.size();j++) fir.pb(tmp[j]);
	}
	sec.pb(0);
	for(i=0;i<s.size();i++)
	{
		tmp.clear();
		for(j=0;j<sec.size();j++)
		{
			tmp.pb(sec[j]);
			tmp.pb(sec[j]-s[i]);
			tmp.pb(sec[j]+s[i]);
		}
		sec.clear();
		for(j=0;j<tmp.size();j++) sec.pb(tmp[j]);
	}
	sort(sec.begin(),sec.end());
	for(i=0;i<fir.size();i++)
	{
		ll add=fir[i]-n;
		j=lower_bound(sec.begin(),sec.end(),add)-sec.begin();
		//printf("%lld %lld %lld\n",fir[i],add,sec[j]);
		if(j!=sec.size() && add==sec[j]) return printf("YES\n"),0;
	}
	printf("NO\n");
	//for(i=0;i<fir.size();i++) printf("%lld ",fir[i]);printf("\n");
	//for(i=0;i<sec.size();i++) printf("%lld ",sec[i]);printf("\n");
	return 0;
}