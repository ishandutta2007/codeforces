#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int P = 135;

unsigned binom[P];

unsigned f[2][P];

int main() {
	int n, p, q;
	scanf("%d%d%d", &n, &p, &q);
	p = min(p, n - 1);
	vector<unsigned> muls;
	binom[0] = 1;
	for (int j = 1; j <= p && n - j + 1 > 0; ++j) {
		muls.push_back(n - j + 1);
		unsigned div = j;
		for (int k = 0; k < (int)muls.size() && div > 1; ++k) {
			unsigned g = __gcd(div, muls[k]);
			if (g > 1) {
				div /= g;
				muls[k] /= g;
			}
		}
		unsigned cur = 1;
		for (int k = 0; k < (int)muls.size(); ++k) {
			cur *= muls[k];
		}
		binom[j] = cur;
	}
	unsigned ans = 0;
	for (int i = 1; i <= q; ++i) {
		unsigned tmp = 0, base = i;
		for (int j = 0; j <= p; ++j) {
			tmp += binom[j] * base;
			base = base * i;
		}
		ans ^= tmp;
	}
	cout << ans << endl;
	return 0;
}