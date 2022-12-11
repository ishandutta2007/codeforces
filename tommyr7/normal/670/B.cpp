#include <bits/stdc++.h>
using namespace std;
int n,k,a[100007];
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int now=0;
	while (k>now)
	{
		k-=now;
		++now;
	}
	printf("%d\n",a[k]);
	return 0;
}