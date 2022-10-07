#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,d,m;
ll a[100005],s1[100005],s2[100005];
int main()
{
	scanf("%d%d%d",&n,&d,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int st=0;
	while(st<=n&&a[st]<=m)st++;
	for(int i=st-1;i>=1;i--)s1[st-i]=s1[st-i-1]+a[i];
	for(int i=st;i<=n;i++)s1[i]=s1[i-1];
	for(int i=n;i>=1;i--)
	{
		if(a[i]>m)s2[n-i+1]=s2[n-i]+a[i];
		else s2[n-i+1]=s2[n-i];
	}
	ll ans=0;
	for(int i=1;(i-1)*d+i<=n;i++)
	  ans=max(ans,s2[i]+s1[n-(i-1)*d-i]);
	ans=max(ans,s1[st-1]);
	printf("%lld\n",ans);
	return 0;
}