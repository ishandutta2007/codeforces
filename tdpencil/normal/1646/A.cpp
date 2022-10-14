#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int test_case;
void solve_componenent() {
	ll n, k;
	scanf("%lld%lld", &n, &k);
	printf("%lld\n",k / (n * n));
}
int main() {
	scanf("%d", &test_case);

	while(test_case--) {
		solve_componenent();
	}
}