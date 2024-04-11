#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <set>
#include <vector>
using namespace std;
#define N 200005
#define ll long long
ll n,k;
int main()
{
	scanf("%lld%lld",&n,&k);
	if(n*2-1<k){puts("0");return 0;}
	printf("%lld\n",min(n,k-1)-(k>>1));
}