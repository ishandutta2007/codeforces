#include <iostream>
#include <algorithm>

typedef long long ll;
typedef std::pair<ll, int> ii;

ii a[200200];

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first;
		a[i].second = i;
	}
	std::sort(a, a + n);
	int m = 0;
	while(a[m].first == a[0].first) {
		m++;
	}
	ll longest = n + a[0].second - a[m - 1].second - 1;
	for(int i = 1; i < m; i++) {
		longest = std::max(a[i].second - a[i - 1].second - 1LL, longest);
	}
	std::cout << a[0].first * n + longest << '\n';
}