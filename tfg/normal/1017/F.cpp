#include <iostream>
#include <vector>
#include <cstring>

const int mh = 202000;

bool np[mh];
std::vector<int> primes;
unsigned int a, b, c, d;

unsigned int solve(unsigned int n, unsigned int p) {
	unsigned int freq = 0;
	while(n) {
		freq += n / p;
		n /= p;
	}
	unsigned int ans = (((a * p + b) * p + c) * p + d) * freq;
	return ans;
}

void segmentedSieve(int l, int r) {
	memset(np, false, sizeof np);
	for(auto p : primes) {
		for(int i = (l + p - 1) / p * p; i <= r; i += p) {
			np[i - l] = true;
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n >> a >> b >> c >> d;
	for(int i = 2; i < mh; i++) {
		if(np[i]) continue;
		primes.push_back(i);
		for(int j = i + i; j < mh; j += i) {
			np[j] = true;
		}
	}
	unsigned int ans = 0;
	for(auto v : primes) {
		/*for(int i = v; i <= n; i += v) {
			std::cout << "(" << v << ", " << i << ")\n";
		}*/
		ans += solve(n, v);
	}
	for(int i = mh; i <= n; i += mh) {
		segmentedSieve(i, i + mh - 1);
		for(int j = 0; j < mh; j++) {
			if(!np[j]) {
				ans += solve(n, i + j);
			}
		}
	}
	std::cout << ans << std::endl;
}