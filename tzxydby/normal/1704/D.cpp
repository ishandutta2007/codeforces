#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,mp;
long long a[N],mx,mn;
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		a[i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			long long v;
			scanf("%lld",&v);
			a[i]+=v*j;
		}
	}
	mx=-1,mn=LLONG_MAX,mp=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>mx)
		{
			mx=a[i];
			mp=i;
		}
		if(a[i]<mn)
			mn=a[i];
	}
	printf("%d %lld\n",mp,mx-mn);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}