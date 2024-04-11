#include <iostream>
#include <cstdio>

typedef long long ll;

int main() {
	int n, k;
	std::cin >> n >> k;
	int rem = 0;
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		ll cur;
		scanf("%lld", &cur);
		//std::cout << "sum is " << sum << "\n";
		//std::cout << "cost is " << sum - (n - i - 1) * cur * i << "\n";
		if(sum - (n - i - 1) * cur * i < k) {
			printf("%d\n", i + rem + 1);
			i--;
			n--;
			rem++;
		} else {
			sum += cur * i;
		}
	}
}