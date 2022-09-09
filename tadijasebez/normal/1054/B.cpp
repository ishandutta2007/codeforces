#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int a[N],mx=-1;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]>mx+1) return printf("%i\n",i),0;
		mx=max(mx,a[i]);
	}
	printf("-1\n");
	return 0;
}