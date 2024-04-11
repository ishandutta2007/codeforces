#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long x,y,a,b;
int main()
{
	scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
	long long gcd=__gcd(a,b);a/=gcd,b/=gcd;
	printf("%lld\n",min(x/a,y/b));
}