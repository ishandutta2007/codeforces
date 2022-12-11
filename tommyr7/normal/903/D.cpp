#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
long  double ans=0;
int n;
int a[Maxn];
map<int,int> mp;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int now=1-n;
	for (int i=1;i<=n;i++)
	{
		ans+=1.0*now*a[i];
		now+=2;
	}
	mp.clear();
	for (int i=1;i<=n;i++)
	{
		ans+=1.0*(mp[a[i]+1]-mp[a[i]-1]);
		++mp[a[i]];
	}
	printf("%.Lf\n",ans);
	return 0;
}