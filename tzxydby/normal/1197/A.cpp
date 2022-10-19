#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		printf("%d\n",min(n-2,a[n-1]-1));
	}
	return 0;
}