#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

int length(int n) {
	return n == 0 ? 0 : 1 + length(n / 10);
}

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::map<int, int> freq[11];
	int n, k;
	std::cin >> n >> k;
	long long ans = 0;
	std::vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		//std::cin >> a[i];
		int t;
		scanf("%d", &t);
		a[i] = t;
		//std::cout << "including " << a[i] << std::endl;
		long long base = 10 % k;
		for(int j = 1; j < 11; j++) {
			freq[j][(base * a[i]) % k]++;
			base = base * 10 % k;
		}
	}
	for(int i = 0; i < n; i++) {
		int len = length(a[i]);
		long long base = 1;
		for(int j = 0; j < len; j++) {
			base = base * 10 % k;
		}
		if((a[i] * base + a[i]) % k == 0) {
			ans--;
		}
		ans += freq[len][(k - a[i] % k) % k];
	}
	std::cout << ans << std::endl;
}