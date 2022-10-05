#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n,a[Maxn],T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		printf("%d\n",min(n-2,a[n-1]-1));
	}
	return 0;
}