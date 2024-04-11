#include <iostream>
#include <cstdio>
#include <map>
#include <cstdlib>
#include <ctime>
#include <algorithm>

typedef long long ll;

const ll MOD = 1e9 + 7;
const int ms = 2e6 + 10;

ll fexp(ll x, ll e) {
	ll ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % MOD;
		}
		x = x * x % MOD;
	}
	return ans;
}

ll fat[ms], ifat[ms];
int a[ms];
int p[ms];

ll comb(int n, int k) {
	return fat[n] * ifat[k] % MOD * ifat[n - k] % MOD;
}

int main() {
	srand(time(0));
	fat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = fat[i - 1] * i % MOD;
		ifat[i] = fexp(fat[i], MOD - 2);
	}
	ifat[0] = 1;
	int n;
	std::cin >> n;
	std::map<int, int> freq;
	for(int i = 0; i < n; i++) {
		int temp;
		scanf("%lli", &temp);
		//temp = rand() % 100;
		freq[temp]++;
		p[i] = i;
		a[i] = temp;
		//std::cout << temp << ' ';
	}
	//std::cout << '\n';
	int lesser = 0;
	ll ans = 0;
	for(auto a : freq) {
		int greater = n - lesser - a.second;
		if(greater != 0) {
			ll count = fat[lesser] * fat[n - lesser - 1] % MOD;
			count = count * a.first % MOD;
			count = count * a.second % MOD;
			count = count * comb(n, lesser);
			//std::cout << "for number " << a.first << " got " << count << "\n";
			ans = (ans + count) % MOD;
		}
		lesser += a.second;
	}
	/*ll wut = 0;
	do {
		ll m = 0, f = 0;
		for(int i = 1; i < n; i++) {
			if(a[p[i]] > a[p[m]]) {
				f += a[p[m]];
				m = i;
			}
		}
		std::cout << "for:";
		for(int i = 0; i < n; i++) {
			std::cout << ' ' << a[p[i]];
		}
		std::cout << ", got " << f << "\n";
		wut += f;
	} while(std::next_permutation(p, p + n));*/
	//std::cout << wut << '\n';
	std::cout << ans << '\n';
}