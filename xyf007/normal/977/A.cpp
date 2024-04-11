#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	while(k--)
	{
		if(n%10)
		{
			n--;
		}
		else
		{
			n/=10;
		}
	}
	printf("%d",n);
	return 0;
}
//f