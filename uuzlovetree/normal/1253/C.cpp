#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
int n,m;
ll a[maxn],s[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		ans+=s[i%m];
		s[i%m]+=a[i];
		ans+=a[i];
		printf("%I64d ",ans);
	}
}