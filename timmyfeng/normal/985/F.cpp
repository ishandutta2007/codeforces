#include <bits/stdc++.h> 
using namespace std;

const int M = (119 << 23) + 1;
const int MX = 2e5 + 1;
const int BS = 137;
const int AL = 26;

int pre_hsh[AL][MX], pow_inv[MX], pow_bs[MX];

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int sub(int a, int b) {
	a -= b;
	return a < 0 ? a + M : a;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

int mod_pow(int b, int e) {
	if (!e)
		return 1;
	if (e % 2)
		return mul(b, mod_pow(b, e - 1));
	int tmp = mod_pow(b, e / 2);
	return mul(tmp, tmp);
}

void init() {
	pow_inv[0] = 1;
	pow_inv[1] = mod_pow(BS, M - 2);
	pow_bs[0] = 1;
	pow_bs[1] = BS;
	for (int i = 2; i < MX; ++i) {
		pow_inv[i] = mul(pow_inv[i - 1], pow_inv[1]);
		pow_bs[i] = mul(pow_bs[i - 1], pow_bs[1]);
	}
}

int get_hsh(int a, int b, int c) {
	return mul(sub(pre_hsh[c][b], pre_hsh[c][a - 1]), pow_inv[a - 1]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();

	int n, m;
	string s;
	cin >> n >> m >> s;

	for (int i = 0; i < AL; ++i) {
		for (int j = 0; j < n; ++j) {
			if (s[j] == 'a' + i) {
				pre_hsh[i][j + 1] = add(pre_hsh[i][j], pow_bs[j]);
			} else {
				pre_hsh[i][j + 1] = pre_hsh[i][j];
			}
		}
	}

	while (m--) {
		int x, y, len;
		cin >> x >> y >> len;

		int mask = 0;
		bool ans = true;
		for (int i = 0; i < AL && ans; ++i) {
			bool ok = false;
			for (int j = 0; j < AL; ++j) {
				if (mask & (1 << j))
					continue;
				if (get_hsh(x, x + len - 1, i) == get_hsh(y, y + len - 1, j)) {
					mask |= 1 << j;
					ok = true;
					break;
				}
			}
			ans &= ok;
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}
}