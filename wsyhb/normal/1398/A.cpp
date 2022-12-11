#include<bits/stdc++.h>
using namespace std;
const int max_n=5e4+5;
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
		if(a[1]+a[2]>a[n])
			puts("-1");
		else
			printf("%d %d %d\n",1,2,n);
	}
	return 0;
}