#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	scanf("%d",&a);
	while(a>9)
	{
		int sum=0;
		while(a)
		{
			sum+=a%10;
			a/=10;
		}
		a=sum;
	}
	printf("%d\n",a);
    return 0;
}