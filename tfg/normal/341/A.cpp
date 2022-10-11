#include <iostream>
#include <vector>
#include <algorithm>

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

void brute(std::vector<int> a) {
	int n = a.size();
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		p[i] = i;
	}
	long long ans = 0;
	do {
		long long cur = 0;
		for(int i = 1; i < n; i++) {
			cur += abs(a[p[i]] - a[p[i-1]]);
		}
		//cur += a[p[0]];
		std::cout << "got " << cur << std::endl;
		ans += cur;
	} while(std::next_permutation(p.begin(), p.end()));
	std::cout << "total is " << ans << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	if(n == 1) {
		long long m;
		std::cin >> m;
		std::cout << m << ' ' << 1 << std::endl;
		return 0;
	}
	long long p = 0;
	long long q = (long long) n;
	long long sum = 0;
	long long tmp = 0;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	for(int i = 0; i < n; i++) {
		int t = a[i];
		//tmp += 2 * ((long long) i * t - (long long) (n - i - 1) * t) * (n - 1);
		p += 2 * ((long long) i * t - (long long) (n - i - 1) * t);
		p += (long long) t;
		sum += t;
	}
	long long g = gcd(p, q);
	p /= g;
	q /= g;
	std::cout << p << ' ' << q << std::endl;
}