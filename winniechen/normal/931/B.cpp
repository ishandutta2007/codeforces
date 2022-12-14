#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;
int a,b,n,x;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	while(a!=b)
	{
		if(a!=1)
		{
			a=(a+1)>>1;
		}
		if(b!=1)
		{
			b=(b+1)>>1;
		}
		x++;
	}
	if((1<<x)>=n)
		printf("Final!\n");
	else
		printf("%d\n",x);
	return 0;
}