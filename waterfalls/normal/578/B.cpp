#include <cstdio>
#include <algorithm>

using namespace std;

int n,k,x;
long long a[200013];
long long pref[200013];
long long suff[200013];

int main() {
	scanf("%d%d%d",&n,&k,&x);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	long long num = 1;
	while (k--) num*=x;
	for (int i=1;i<=n;i++) pref[i] = (a[i]|pref[i-1]);
	for (int i=n;i>=0;i--) suff[i] = (a[i]|suff[i+1]);
	long long ans = 0;
	for (int i=1;i<=n;i++) {
		long long cur = a[i]*num;
		cur|=pref[i-1];
		cur|=suff[i+1];
		ans = max(ans,cur);
	}
	printf("%lld\n",ans);

	return 0;
}