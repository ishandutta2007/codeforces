#include <bits/stdc++.h>
using namespace std;
const int N=500;
int a[N];
int main()
{
	int n,i,m;
	scanf("%i %i",&n,&m);
	int mn=0;
	for(i=1;i<=n;i++) scanf("%i",&a[i]),mn=max(mn,a[i]);
	mn+=m;
	while(m--)
	{
		int j=0;
		for(i=1;i<=n;i++) if(!j || a[j]>a[i]) j=i;
		a[j]++;
	}
	int mx=0;
	for(i=1;i<=n;i++) mx=max(mx,a[i]);
	printf("%i %i\n",mx,mn);
	return 0;
}