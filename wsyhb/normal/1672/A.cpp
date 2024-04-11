#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int sum=0;
		for(int i=1;i<=n;++i)
		{
			int a;
			scanf("%d",&a);
			sum+=a;
		}
		if((sum-n)&1)
			puts("errorgorn");
		else
			puts("maomao90"); 
	}
	return 0;
}