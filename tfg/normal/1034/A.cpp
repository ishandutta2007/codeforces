#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdio>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1.6e7;

int gcd(int a, int b) {
	if(b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int pr[ms];
int freq[ms];

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 2; i < ms; i++) {
		if(pr[i] != 0) {
			continue;
		}
		pr[i] = i;
		if((long long) i * i >= ms) {
		    continue;
		}
		for(int j = i * i; j < ms; j += i) {
			pr[j] = i;
		}
	}
	int n;
	std::cin >> n;
	int g = 0;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		//std::cin >> a[i];
		scanf("%d", &a[i]);
		g = gcd(g, a[i]);
	}
	bool valid = false;
	for(int i = 0; i < n; i++) {
		a[i] /= g;
		if(a[i] > 1) {
			valid = true;
		}
	}
	if(!valid) {
		std::cout << "-1\n";
		return 0;
	}
	for(int i = 0; i < n; i++) {
		int x = a[i];
		while(x > 1) {
			int p = pr[x];
			while(x % p == 0) {
				x /= p;
			}
			freq[p]++;
		}
	}
	int ans = n - 1;
	for(int i = 2; i < ms; i++) {
		ans = std::min(ans, n - freq[i]);
	}
	std::cout << ans << std::endl;
}