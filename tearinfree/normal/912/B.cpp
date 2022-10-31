#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <queue>

using namespace std;
typedef long long lli;


int main() {
	lli n,k;
	scanf("%lld%lld",&n,&k);
	if(k>=2) {
		lli t=1;
		while(t<=n) t<<=1;
		printf("%lld\n",t-1);
	}
	else printf("%lld\n",n);
	return 0;
}