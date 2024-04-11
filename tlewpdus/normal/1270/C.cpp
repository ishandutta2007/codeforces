#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MOD = 1e9+7;
const int INT = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
ll arr[100100];

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ll A = 0, B = 0;
		for (int i=0;i<n;i++) {
			scanf("%lld",&arr[i]);
			A += arr[i];
			B ^= arr[i];
		}
		printf("2\n%lld %lld\n",B,A+B);
	}

	return 0;
}