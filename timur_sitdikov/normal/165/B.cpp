#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

long long calc(long long n, long long k, long long val)
{
	long long sum, j;
	for(sum=0, j=1; ; j*=k)
	{
		if (val/j==0) return sum;
		sum+=val/j;
	}
}

int main()
{	
	long long n, k, i, j, p, q, sum;
	scanf("%I64d %I64d", &n, &k);
	for(p=1, q=1000000000; p+1<q;)
	{
		i=(p+q)>>1;
		sum=calc(n, k, i);
		if (sum<n) p=i+1;
		else q=i;
	}
	sum=calc(n, k, p);
	if (sum<n) p++;
	printf("%I64d", p);
}