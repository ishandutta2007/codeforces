#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
// #define N 1000005
long long n,k;
int main()
{
	scanf("%lld%lld",&n,&k);
	if(k%n==0)printf("%lld\n",k/n);
	else printf("%lld\n",k/n+1);
}