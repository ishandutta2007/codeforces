#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int d=unique(a+1,a+n+1)-a-1;
		printf("%d\n",d);
	}
}