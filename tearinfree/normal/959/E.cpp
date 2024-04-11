#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long lli;

int main() {
	lli n,l,ans=0;
	scanf("%lld",&n);

	for(l=2;l<=n;l*=2) {
		ans += (l/2) * (n/l);
		
		lli rem = n%l;
		if(rem > l/2) ans += l/2;

	}
	lli rem = n % l;
	if(rem > l/2) ans += l/2;
	
	printf("%lld\n",ans);
}