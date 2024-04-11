#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n;
ll k;
ll arr[200100];

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&n);
		ll sum = 0;
		for (int i=0;i<n;i++) {
			scanf("%lld",&arr[i]);
			if (i) {
				sum += max(arr[i-1]-arr[i],0LL);
			}
		}
		printf("%lld\n",sum);

	}

	return 0;
}