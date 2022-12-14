#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
long long n,m,a,b;
int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
	printf("%lld\n",min((n%m)*b,(m-(n%m))*a));
}