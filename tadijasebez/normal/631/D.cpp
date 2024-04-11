#include <stdio.h>
#include <map>
using namespace std;
#define ll long long
const int N=200050;
const ll mod=5645789545631ll;//1e9+7;
map< pair<ll,char> ,int> id;
int cnt;
ll sol;
pair<ll,char> a[N],b[N],tmp;
int c[N],d[N];
ll Hash[N],Hash1;
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	int last=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld-%c",&tmp.first,&tmp.second);
		if(tmp.second==a[last].second) a[last].first+=tmp.first;
		else a[++last]=tmp;
	}
	n=last;
	for(i=1;i<=n;i++)
	{
		//scanf("%i-%c",&a[i].first,&a[i].second);
		if(!id[a[i]]) id[a[i]]=++cnt;
		c[i]=id[a[i]];
	}
	last=0;
	for(i=1;i<=m;i++)
	{
		scanf("%lld-%c",&tmp.first,&tmp.second);
		if(tmp.second==b[last].second) b[last].first+=tmp.first;
		else b[++last]=tmp;
	}
	m=last;
	for(i=1;i<=m;i++)
	{
		//scanf("%i-%c",&b[i].first,&b[i].second);
		if(!id[b[i]]) id[b[i]]=++cnt;
		d[i]=id[b[i]];
	}
	if(n<m) return printf("0\n"),0;
	for(i=2;i<m;i++) Hash1=Hash1*cnt%mod,Hash1=(Hash1+d[i])%mod;
	if(m==1)
	{
		for(i=1;i<=n;i++) if(a[i].second==b[1].second && a[i].first>=b[1].first) sol+=a[i].first-b[1].first+1;
		printf("%lld\n",sol);
		return 0;
	}
	if(m==2)
	{
		for(i=1;i<n;i++) if(a[i].second==b[1].second && a[i].first>=b[1].first && a[i+1].second==b[2].second && a[i+1].first>=b[2].first) sol++;
		printf("%lld\n",sol);
		return 0;
	}
	ll pow=1;
	for(i=1;i<m-2;i++) pow=pow*cnt%mod;
	//printf("%i %i %i\n",cnt,pow,Hash1);
	for(i=1;i<=m-2;i++) Hash[1]=Hash[1]*cnt%mod,Hash[1]=(Hash[1]+c[i])%mod;
	//printf("%i ",Hash[1]);
	for(i=2;i<=n-m+2+1;i++)
	{
		Hash[i]=Hash[i-1];
		Hash[i]-=pow*c[i-1]%mod;
		if(Hash[i]<0) Hash[i]+=mod;
		Hash[i]=Hash[i]*cnt%mod;
		Hash[i]=(Hash[i]+c[i+m-2-1])%mod;
		//printf("%i ",Hash[i]);
	}
	//printf("\n");
	for(i=1;i<=n-m+1;i++)
	{
		if(a[i].second==b[1].second && a[i].first>=b[1].first && a[i+m-1].second==b[m].second && a[i+m-1].first>=b[m].first)
		{
			if(Hash1==Hash[i+1]) sol++;
		}
	}
	printf("%lld\n",sol);
	return 0;
}