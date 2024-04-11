#include<bits/stdc++.h>
using namespace std;
const int N=300005,mod=998244353;
long long fac[N]={1};
pair<int,int>a[N];
map<pair<int,int>,int>mp;
bool cmp1(pair<int,int>x,pair<int,int>y)
{
	return x.first<y.first; 
}
bool cmp2(pair<int,int>x,pair<int,int>y)
{
	if(x.second==y.second) return x.first<y.first;
	return x.second<y.second; 
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%mod;
	long long ans=fac[n],k,las;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].first,&a[i].second);
		mp[a[i]]++;
	}
	sort(a+1,a+n+1,cmp1);
	k=1,las=1,i=2;
	while(1)
	{
		while(i<=n&&a[i].first==a[las].first)
			i++;
		k=k*fac[i-las]%mod;
		las=i;
		if(i==n+1)
			break;
	}
	ans=(ans-k+mod)%mod;
	sort(a+1,a+n+1,cmp2);
	k=1,las=1,i=2;
	while(1)
	{
		while(i<=n&&a[i].second==a[las].second)
			i++;
		k=k*fac[i-las]%mod;
		las=i;
		if(i==n+1)
			break;
	}
	ans=(ans-k+mod)%mod;
	int flag=1;
	for(int i=2;i<=n;i++)
		if(a[i].first<a[i-1].first)
			flag=0;
	if(flag)
	{
		k=1;
		for(auto it:mp)
			k=k*fac[it.second]%mod;
		ans=(ans+k)%mod;
	} 
	printf("%d\n",ans);
	return 0;
}