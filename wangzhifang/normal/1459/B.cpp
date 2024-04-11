#include <cstdio>
#define cs const
#define il inline
using namespace std;
typedef long long ll;
int main(){
	ll t;
	scanf("%lld",&t);
	ll x=(t+2)*(t+2)/2;
	if(t&1)
		printf("%lld\n",x);
	else
		printf("%lld\n",x/2);
	return 0;
}