#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int h,m,a;
int main()
{
	scanf("%d:%d %d",&h,&m,&a);
	while(a--)
	{
		++m; h+=m/60; m%=60; h%=24;
	}
	printf("%02d:%02d\n",h,m);
}