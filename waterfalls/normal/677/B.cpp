#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,h,k;
int a[100013];

int main() {
	scanf("%d%d%d",&n,&h,&k);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int has = 0;
	int on = 0;
	ll ans = 0;
	while (on<n) {
		int go = (a[on]-(h-has)+k-1)/k;
		ans+=go;
		has = max(0,has-go*k);
		while (on<n && has+a[on]<=h) has+=a[on++];
	}
	ans+=(has+k-1)/k;
	printf("%lld\n",ans);

	return 0;
}