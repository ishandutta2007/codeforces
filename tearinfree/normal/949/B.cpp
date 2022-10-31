#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long lli;

lli n;
int q;

int main() {
	scanf("%lld%d",&n,&q);
	while(q--) {
		lli val;
		scanf("%lld",&val);
		if(val%2==1) {
			printf("%lld\n",(val+1)/2);
			continue;
		}
		
		lli l=1,cur=val,r=n;
		while((cur-l+1)%2==0) {
			lli t=cur;
			r = cur = (cur-l+1)/2 + r;
			l = t + 1;
		}
		printf("%lld\n",(cur+1)/2);
	}
	return 0;
}