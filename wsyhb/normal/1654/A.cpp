#include<bits/stdc++.h>
using namespace std;
const int max_n=1e3+5;
int a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		printf("%d\n",a[n-1]+a[n]);
	}
	return 0;
}