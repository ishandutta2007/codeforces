#include <iostream>
#include <vector>
#include <set>
#include <map>

const int ms = 2e4 + 10;

bool np[ms];
std::vector<int> primes;

int getGroup(int n) {
	if(n == 0) return 0;
	int ans = 1;
	if(n < 0) {
		ans = -1;
		n = -n;
	}
	for(auto v : primes) {
		if(v * v > n) {
			break;
		}
		int e = 0;
		while(n % v == 0) {
			e++;
			n /= v;
		}
		if(e & 1) {
			ans *= v;
		}
	}
	return n * ans;
}

int ans[ms];
int a[ms];
int back[ms];

int main() {
	for(int i = 2; i < ms; i++) {
		if(np[i]) continue;
		primes.push_back(i);
		for(int j = i + i; j < ms; j += i) np[j] = true;
	}
	int n;
	std::cin >> n;
	std::map<int, int> prv;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] = getGroup(a[i]);
		back[i] = prv[a[i]];
		prv[a[i]] = i;
		//std::cout << i << ": (" << a[i] << ", " << back[i] << ")\n";
	}
	for(int i = 1; i <= n; i++) {
		int groups = 0;
		for(int j = i; j <= n; j++) {
			if(back[j] < i && a[j] != 0) {
				//std::cout << "on " << i << ", " << j << ", increasing\n";
				groups++;
			}
			//std::cout << "on " << i << ", " << j << " = " << groups << std::endl;
			ans[std::max(1, groups)]++;
		}
	}
	for(int i = 1; i <= n; i++) {
		std::cout << ans[i] << (i == n ? '\n' : ' ');
	}
}