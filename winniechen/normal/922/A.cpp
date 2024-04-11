#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int a,b;
int main()
{
	scanf("%d%d",&a,&b);
	if(b==1&&a)
	{
	    printf("No\n");
	    return 0;
	}
	if(a<0||b<=0)
	{
		printf("No\n");
		return 0;
	}
	if(a<b-1)
	{
		printf("No\n");
		return 0;
	}
	if((a-b+1)&1)
	{
		printf("No\n");
	}else
	{
		printf("Yes\n");
	}
	return 0;
}