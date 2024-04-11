#include <iostream>
#include <vector>
#include <algorithm>

const int ms = 100100;

int a[ms], b[ms], m;
int freq[ms];
int cur_freq[ms];

int o;

bool can(int x) {
	bool ans = true;
	for(int i = x + 1; i <= m - 1 - i; i++) {
		ans = ans && b[i] == b[m - 1 - i];
	}
	for(int i = 0; i <= x; i++) {
		cur_freq[b[i]]++;
	}
	for(int i = std::max(x + 1, m - 1 - x); i < m; i++) {
		cur_freq[b[i]]--;
		ans = ans && cur_freq[b[i]] >= 0;
	}
	if(m % 2 == 1 && x >= m / 2) {
		ans = ans && cur_freq[o] > 0;
	}
	for(int i = 0; i <= x; i++) {
		cur_freq[b[i]]--;
	}
	for(int i = std::max(x + 1, m - 1 - x); i < m; i++) {
		cur_freq[b[i]]++;
	}
	return ans;
}

int solve() {
	int l = 0, r = m - 1;
	if(m % 2 == 1 && freq[b[m / 2]] % 2 != 1) {
		while(l < m && freq[b[l]] % 2 != 1) {
			l++;
		}
		o = b[l];
		l = std::max(l, m / 2);
	}
	//std::cout << "(" << l << ", " << r << ")\n";
	while(l != r) {
		int mid = (l + r) / 2;
		if(can(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	//std::cout << l << '\n';
	//std::cout << m - l - 1 << '\n';
	return m - l - 1;
}

int main() {
	int n;
	std::cin >> n;
	int odd = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(freq[a[i]] & 1) odd--;
		else odd++;
		freq[a[i]]++;
	}
	for(int i = 0; i <= n; i++) {
		if(freq[i] % 2 == 1) {
			o = i;
		}
	}
	int l = 0, r = n - 1;
	while(l <= r && a[l] == a[r]) {
		l++;
		r--;
	}
	if(l > r) {
		std::cout << (long long) n * (n + 1) / 2 << '\n';
		return 0;
	} else if(odd > 1) {
		std::cout << 0 << '\n';
		return 0;
	}
	for(int i = l; i <= r; i++) {
		b[m++] = a[i];
	}
	long long count = solve();
	std::reverse(b, b + m);
	count += solve();
	std::cout << (long long) (l + 1) * (l + count + 1) << '\n';
}