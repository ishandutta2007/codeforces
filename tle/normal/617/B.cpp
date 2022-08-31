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
long long fn=1;
int n,cs[2333],cn=0;
int nut[2333];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int cur;
		scanf("%d",&cur);
		if(cur) cs[++cn]=i;
	}
	if(cn==0)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<cn;i++)
	{
		fn*=cs[i+1]-cs[i];
	}
	printf("%I64d\n",fn);
}