#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
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
		bool flag=(n%2==0);
		for(int i=1;i<=n;++i)
			flag&=(a[i]==a[i%2?1:2]);
		if(flag)
			printf("%d\n",n/2+1);
		else
			printf("%d\n",n);
	}
	return 0;
}