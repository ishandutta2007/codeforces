#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%i",&t);
	while(t--)
	{
		int a[5];
		for(int i=1;i<=4;i++)
		{
			scanf("%i",&a[i]);
		}
		sort(a+1,a+5);
		printf("%i\n",a[1]*a[3]);
	}
	return 0;
}