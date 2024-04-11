#include <bits/stdc++.h>
#define Maxn 2007
using namespace std;
int n,k1,k2;
int a[Maxn],b[Maxn];
int main()
{
	scanf("%d%d%d",&n,&k1,&k2);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for (int i=1;i<=n;i++)
		a[i]=abs(a[i]-b[i]);
	k1+=k2;
	while (k1--)
	{
		int pos=1;
		for (int i=2;i<=n;i++)
			if (abs(a[i])>abs(a[pos])) pos=i;
		a[pos]=abs(a[pos])-1;
		a[pos]=abs(a[pos]);
	}
	long long res=0;
	for (int i=1;i<=n;i++)
		res+=1LL*a[i]*a[i];
	printf("%lld\n",res);
	return 0;
}