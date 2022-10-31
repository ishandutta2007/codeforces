#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <queue>

using namespace std;
typedef long long lli;


int main() {
	lli a,b,x,y,z;
	scanf("%lld%lld%lld%lld%lld",&a,&b,&x,&y,&z);
	a-= x*2; a-=y; b-=y; b-=3*z;
	
	lli sum=max(0ll,-a) + max(0ll,-b);
	printf("%lld\n",sum);
}