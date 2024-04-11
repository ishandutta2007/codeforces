#include <iostream>
#include <vector>

long long solve(long long x) {
	return std::max(x + 1, 0LL);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<int> value;
	std::vector<bool> zero;
	for(int l = 0, r = 0; l < n; l = r) {
		if(a[l] != 1) {
			value.push_back(a[r++]);
			zero.push_back(false);
		} else {
			value.push_back(0);
			zero.push_back(true);
			while(r < n && a[r] == 1) {
				value.back()++;
				r++;
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < value.size(); i++) {
		long long sum = 0;
		long long prod = 1;
		if(zero[i]) {
		    ans += k == 1 ? value[i] : 0;
			continue;
		}
		int left = (i > 0 && zero[i-1] ? value[i-1] : 0);
		long long rest = 3e18;
		for(int j = i; j < value.size(); j++) {
			sum += value[j];
			if(zero[j]) {
				continue;
			}
			prod *= value[j];
			rest /= value[j];
			//std::cout << "on segment [" << i + 1 << ", " << j + 1 << "] with (" << prod << ", " << sum << ")\n";
			if(rest == 0) break;
			int right = (j+1 < value.size() && zero[j+1] ? value[j+1] : 0);
			if(prod % k != 0) continue;
			long long wants = prod / k;
			long long remain = -sum + wants;
			//std::cout << "on segment [" << i + 1 << ", " << j + 1 << "] with " << remain << "\n";
			//std::cout << left + right << "\n";
			if(left + right < remain || remain < 0) continue;
			ans += solve(remain) - solve(remain - left - 1) - solve(remain - right - 1) + solve(remain - left - 1 - right - 1);
			//std::cout << "got (" << solve(remain) << ", " << solve(remain - left - 1) << ", " << solve(remain - right - 1) << ", " << solve(remain - left - right - 2) << ")\n";
		}
	}
	std::cout << ans << std::endl;
}