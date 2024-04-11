#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <cstdlib>
using namespace std;
int f;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a>b)swap(a,b),f=1;
	if(a==1)
	{
		if(b==1)puts("=");
		else
		{
			if(f)puts(">");
			else puts("<");
		}
		return 0;
	}
	if(a==2&&b==3)
	{
		if(f)puts(">");
		else puts("<");
		return 0;
	}
	if(a==b||(a==2&&b==4))
	{
		puts("=");
		return 0;
	}
	if(f)puts("<");
	else puts(">");
	return 0;
}