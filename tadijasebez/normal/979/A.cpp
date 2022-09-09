#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long

int main()
{
	ll n;
	scanf("%lld",&n);
	n++;
	if(n==1) printf("0\n");
	else if(n&1) printf("%lld\n",n);
	else printf("%lld\n",n/2);
	return 0;
}