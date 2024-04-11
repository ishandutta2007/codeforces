#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
long long total(long long mid)
{
	long long sum=0,i;
	for (i=2;mid/(i*i*i);i++)
		sum+=mid/(i*i*i);
	return sum;
}
int main()
{
	long long i,left,right,mid,m;
	scanf("%I64d",&m);
	left=0;
	right=m<<3;
	while (left<right-1)
	{
		mid=(left+right)/2;
		if (total(mid)>=m)
			right=mid;
		else
			left=mid;
	}
	if (total(left)==m)
		printf("%I64d",left);
	else
		if (total(right)==m)
			printf("%I64d",right);
	else
		printf("-1");
	return 0;
}