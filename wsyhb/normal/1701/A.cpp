#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a[2][2],sum=0;
		for(int i=0;i<=1;++i)
			for(int j=0;j<=1;++j)
			{
				scanf("%d",&a[i][j]);
				sum+=a[i][j];
			}
		if(sum==4)
			puts("2");
		else if(sum)
			puts("1");
		else
			puts("0");
	}
	return 0;
}