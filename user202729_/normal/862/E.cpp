#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using ll = long long;

/// Return -1<sup>x</sup>.
int pow_1 (int x) {
	return (x & 1) ? -1 : 1;
}

ll abs(ll x){return x<0?-x:x;}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int lenA, lenB, nquery;
	std::cin >> lenA >> lenB >> nquery;
	std::vector<int> a (lenA), b (lenB);
	#warning "Sum must be ll"
	for (int& i : a) std::cin >> i;
	for (int& i : b) std::cin >> i;
	ll sum = 0;
	for (int i = 0; i < lenA; ++i) sum += b[i] * pow_1(i);
	std::vector<ll> sums;
	int left = 0;
	while (true) {
		sums.push_back(sum);
		if (left + lenA == lenB) break;
		sum = - (sum - b[left] + pow_1(lenA) * b[left + lenA]);
		++left;
	}
//	if (sums.size() != lenB - lenA + 1) {
//		for (ll x : sums) std::cout << x << ' ';
//		return -1;
//	}
	std::sort(sums.begin(), sums.end());
	ll sumA = 0;
	for (int i = 0; i < lenA; ++i) sumA += a[i] * pow_1(i);
	std::vector<ll>::iterator it = std::lower_bound(sums.begin(), sums.end(), sumA);
	ll nearest = -1;
	if (it != sums.end() && (nearest == -1 || abs(nearest-sumA) > abs(*it-sumA))) nearest = *it;
	if (it != sums.begin()) {
		--it;
		if (nearest == -1 || abs(nearest-sumA) > abs(*it-sumA)) nearest = *it;
	}
	std::cout << abs(nearest-sumA) << '\n';
	while (nquery --> 0) {
		int l, r; ll delta;
		std::cin >> l >> r >> delta;
		--l;
		if ((r - l) % 2 != 0) {
			sumA += pow_1(l) * delta;
		}
		std::vector<ll>::iterator it = std::lower_bound(sums.begin(), sums.end(), sumA);
		ll nearest = -1;
		if (it != sums.end() && (nearest == -1 || abs(nearest-sumA) > abs(*it-sumA))) nearest = *it;
		if (it != sums.begin()) {
			--it;
			if (nearest == -1 || abs(nearest-sumA) > abs(*it-sumA)) nearest = *it;
		}
		std::cout << abs(nearest-sumA) << '\n';
//		std::cerr << "sumA = " << sumA << '\n';
	}
	return 0;
}