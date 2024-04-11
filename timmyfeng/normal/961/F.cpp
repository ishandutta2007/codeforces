#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e6 + 1;
const int M = 1e9 + 7;
const int BS = 137;

int pre_hsh[MX], pow_bs[MX];

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

void init() {
	pow_bs[0] = 1;
	for (int i = 1; i < MX; ++i) {
		pow_bs[i] = mul(pow_bs[i - 1], BS);
	}
}

int get_hsh(int a, int len) {
	return sub(pre_hsh[a + len], mul(pre_hsh[a], pow_bs[len]));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();

	int n;
	string s;
	cin >> n >> s;

	for (int i = 1; i <= n; ++i) {
		pre_hsh[i] = add(mul(pre_hsh[i - 1], BS), s[i - 1] - 'a');
	}

	vector<int> ans((n - 1) / 2 + 1);
	if (n % 2 || s[(n - 1) / 2] != s[n / 2]) {
		ans.back() = -1;
	} else {
		ans.back() = 1;
	}

	for (int l = (n - 1) / 2 - 1; l >= 0; --l) {
		int r = n - l - 1;
		ans[l] = ans[l + 1] + 2;
		while (ans[l] > -1 && get_hsh(l, ans[l]) != get_hsh(r - ans[l] + 1, ans[l])) {
			ans[l] -= 2;
		}
	}

	for (int i = 0; i <= (n - 1) / 2; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}