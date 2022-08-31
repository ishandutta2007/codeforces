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
int seg[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	long long ans=0;
	for(int i=a;i<=b;i++)
	{
		int cur=i;
		while(cur) ans+=seg[cur%10], cur/=10;
	}
	printf("%I64d\n",ans);
}