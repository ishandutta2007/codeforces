#include <bits/stdc++.h>
#define Maxn 5007
using namespace std;
int n;
int a[Maxn];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int lx=1,rx=2;
	while (rx<=n)
	{
		if (a[lx]<a[rx]) ++lx;
		++rx;
	}
	printf("%d\n",rx-lx);
	return 0;
}