#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
ll arr[100100];

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%lld",&arr[i]);
		ll maxi = arr[0], gap = 0;
		for (int i=1;i<n;i++) {
			gap = max(gap,maxi-arr[i]);
			maxi = max(maxi,arr[i]);
		}
		int c = 0;
		while(gap) {
			gap/=2;
			c++;
		}
		printf("%d\n",c);
	}

	return 0;
}