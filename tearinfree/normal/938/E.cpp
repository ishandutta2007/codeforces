#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long lli;

const lli mod=1e9+7;

int n;
lli arr[1000001],fact[1000001];

lli power(lli a,lli p) {
	lli ans = 1;
	while(p) {
		if(p&1) ans = ans * a % mod;
		a = a * a % mod;
		p >>= 1;
	}
	return ans;
}
lli inv(lli a) { return power(a, mod-2); }

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",arr+i);
	sort(arr,arr+n);

	fact[0] = 1;
	for(int i=1;i<=n; i++) fact[i] = fact[i-1] * i % mod;

	int l=0;
	lli ans = 0;
	for(int i=0;i<n;i++) {
		if(arr[i] == arr[n-1]) break;
		if(i!=0 && arr[i] != arr[i-1]) l = i;
		ans = (ans + arr[i] * fact[n]  % mod * inv(n - l) % mod) % mod;
	}
	printf("%lld\n",ans);

	return 0;
}