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
		scanf("%d%lld",&n,&k);
		ll maxi = -LINF, mini = LINF;
		for (int i=0;i<n;i++) {
			scanf("%lld",&arr[i]);
			maxi = max(maxi,arr[i]);
			mini = min(mini,arr[i]);
		}
		if (k%2) {
			for (int i=0;i<n;i++) printf("%lld ",maxi-arr[i]);
			puts("");
		}
		else {
			for (int i=0;i<n;i++) printf("%lld ",arr[i]-mini);
			puts("");
		}
	}

	return 0;
}