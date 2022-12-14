#include <cstdio>
using namespace std;
#define mod 1000000007
int main(){
	int t;
	long long m;
	for(scanf("%d",&t); t; --t){
		scanf("%lld",&m);
		printf("%lld\n",(m/4+1)%mod*((m/2-m/4+1)%mod)%mod);
	}
	return 0;
}