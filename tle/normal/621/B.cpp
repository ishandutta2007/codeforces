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
int n,x[233333],y[233333],xpy[233333],xmy[233333];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",x+i,y+i);
		xpy[x[i]+y[i]]++;
		xmy[x[i]-y[i]+1000]++;
	}
	long long s=0;
	for(int i=0;i<=2333;i++)
	{
		s+=(long long)(xpy[i]-1)*xpy[i]/2;
		s+=(long long)(xmy[i]-1)*xmy[i]/2;
	}
	cout<<s;
}