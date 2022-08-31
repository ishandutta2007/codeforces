#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n,l[233333];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",l+i);
	sort(l+1,l+1+n);
	long long sum=0;
	for(int i=1;i<n;i++) sum+=l[i];
	printf("%I64d\n",l[n]-sum+1);
}