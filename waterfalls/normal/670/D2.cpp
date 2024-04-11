#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k;
int a[100013], b[100013];

bool check(ll num) {
	ll need = 0;
	for (int i=0;i<n;i++) {
		need+=max(0LL,a[i]*num-b[i]);
		if (need>k) return false;
	}
	return true;
}

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n;i++) scanf("%d",&b[i]);
	ll low = 0;
	ll high = 2.1e9;
	while (high-low>1) {
		if (check((low+high)/2)) low = (low+high)/2;
		else high = (low+high)/2;
	}
	printf("%lld\n",low);

	return 0;
}