#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
#define N 1000005
#define ll long long
#define mod 1000000007
int n,k,lg[N];ll ans,a[N],mx[N],s[N];
void solve(int l,int r)
{
	if(r-l+1<k)return ;int m=(l+r)>>1;mx[m]=a[m];s[m]=0;s[l-1]=0;
	for(int i=m-1;i>=l;i--)mx[i]=max(mx[i+1],a[i]),s[i]=0;
	for(int i=l;i<=m;i++)
	{
		int x=i-k+1;if(x>=l)s[i]=s[x];
		s[i]+=mx[i];s[i]%=mod;
	}ll maxx=a[m+1];
	for(int i=m+1,j=m;i<=r;i++,maxx=max(maxx,a[i]))
	{
		if(i-l+1<k)continue;
		while(j>=l&&mx[j]<maxx)j--;
		int x=i-j,t=(x-1)/(k-1),u=t+1;t-=(i-m-1)/(k-1);
		ans+=maxx*t%mod+s[max(i-(u*(k-1)),l-1)];ans%=mod;
	}solve(l,m);solve(m+1,r);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	solve(1,n);
	printf("%lld\n",ans);
}