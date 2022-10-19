#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int m=n*2;
		for(int i=1;i<=m;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+m+1);
		printf("%d\n",a[n+1]-a[n]);
	}
	return 0;
}