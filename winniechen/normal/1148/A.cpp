#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
long long A,B,C;
int main()
{
	scanf("%lld%lld%lld",&A,&B,&C);
	if(A==B)printf("%lld\n",C*2+A+B);
	else if(A<B)printf("%lld\n",C*2+A+A+1);
	else printf("%lld\n",C*2+B+B+1);
}