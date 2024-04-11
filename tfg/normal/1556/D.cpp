#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool debug = false;
int wtf[100100];

int qry(int i, int j, char op) {
	assert(i != j);
	std::cout << (op == '&' ? "and" : "or") << ' ' << i+1 << ' ' << j+1 << std::endl;
	int ans;
	if(!debug) {
		std::cin >> ans;
	} else {
		ans = op == '&' ? (wtf[i] & wtf[j]) : (wtf[i] | wtf[j]);
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	if(debug) {
		for(int i = 0; i < n; i++) {
			//std::cin >> wtf[i];
			wtf[i] = rng() % 1024;
			if(i % 2 == 0) {
				wtf[i] ^= 1024;
			}
		}
	}
	int unknown = (1 << 30) - 1;
	std::vector<int> o(n, 0), a(n, 0);
	std::vector<int> prefixXor(n, 0);
	int all = 0;
	for(int i = 1; i < n; i++) {
		o[i] = qry(i-1, i, '|');
		a[i] = qry(i-1, i, '&');
		prefixXor[i] = o[i] ^ a[i];
		all |= o[i];
		while(a[i] & unknown) {
			int inter = a[i] & unknown;
			int bit = 0;
			while(!((1 << bit) & inter)) {
				bit++;
			}
			unknown ^= 1 << bit;
			int f = (1 << bit);
			for(int j = i; j > 0; j--) {
				f ^= o[j] ^ a[j];
			}
			prefixXor[0] ^= f & (1 << bit);
		}
		while((~o[i]) & unknown) {
			int inter = (~o[i]) & unknown;
			int bit = 0;
			while(!((1 << bit) & inter)) {
				bit++;
			}
			unknown ^= 1 << bit;
			int f = 0;
			for(int j = i; j > 0; j--) {
				f ^= o[j] ^ a[j];
			}
			prefixXor[0] ^= f & (1 << bit);
		}
	}
	{
		int val = qry(0, 2, '&') & unknown;
		assert((val & prefixXor[0]) == 0);
		prefixXor[0] ^= val;
	}
	for(int i = 1; i < n; i++) {
		prefixXor[i] ^= prefixXor[i-1];
	}
	if(debug) {
		for(int i = 0; i < n; i++) {
			std::cerr << prefixXor[i] << (i + 1 == n ? '\n' : ' ');
		}
		for(int i = 0; i < n; i++) {
			std::cerr << wtf[i] << (i + 1 == n ? '\n' : ' ');
		}
	}
	std::sort(prefixXor.begin(), prefixXor.end());
	std::cout << "finish " << prefixXor[k-1] << std::endl;
}