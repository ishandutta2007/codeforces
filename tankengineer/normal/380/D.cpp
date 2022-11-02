#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;
const int N = 100005;
int n, a[N], f[N], rev[N];

int reverse(int i) {
	return i == 1 ? 1 : (long long)(MOD - MOD / i) * reverse(MOD % i) % MOD;
}

int combo(int n, int m) {
	return (long long)f[n] * rev[m] % MOD * rev[n - m] % MOD;
}

int pow2(int n) {
	if (n == -1) {
		return 1;
	}
	int ret = 1;
	while (n--) {
		ret <<= 1;
		ret %= MOD;
	}
	return ret;
}

vector<pair<int, int> > evt;

int solve(int t, int l, int r) {
	long long ret = 1;
	for (int i = 0; i < (int)evt.size(); ++i) {
		int newt = evt[i].first, pos = evt[i].second;
		int delta = newt - t - 1, left, right;
		if (pos < l) {
			left = l - pos - 1;
			right = delta - left;
		} else if (pos > r) {
			right = pos - r - 1;
			left = delta - right;
		} else {
			return 0;
		}
		if (right < 0 || left < 0) {
			return 0;
		}
		ret = ret * combo(delta, right) % MOD;
		if (pos < l) {
			l = pos;
			r += right;
		} else {
			r = pos;
			l -= left;
		}
		t = newt;
	}
	if (t < n) {
		ret = ret * combo(n - t, l) % MOD;
	}
	return ret;
}

int main() {
	f[0] = 1;
	rev[0] = 1;
	for (int i = 1; i < N; ++i) {
		f[i] = (long long)f[i - 1] * i % MOD;
		rev[i] = reverse(f[i]);
	}
	scanf("%d", &n);
	int mint = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		if (a[i] > 0) {
			if (mint == -1 || a[i] < a[mint]) {
				mint = i;
			}
		}
	}
	if (mint == -1) {
		printf("%d\n", pow2(n - 1));
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] > 0) {
			evt.push_back(make_pair(a[i], i));
		}
	}
	sort(evt.begin(), evt.end());
	int ans = 0;
	if (mint >= a[mint] - 1 && a[mint] != 1) {
		bool flag = true;
		for (int i = a[mint]; flag && i >= 2; --i) {
			if (a[mint - i + 1] != 0) {
				flag = false;
			}
		}
		if (flag) {
			ans += (long long)pow2(a[mint] - 2) * solve(a[mint] - 1, mint - a[mint] + 1, mint - 1) % MOD;
		}
	}
	if (mint + a[mint] - 1 < n) {
		bool flag = true;
		for (int i = a[mint]; flag && i >= 2; --i) {
			if (a[mint + i - 1] != 0) {
				flag = false;
			}
		}
		if (flag) {
			ans += (long long)pow2(a[mint] - 2) * solve(a[mint] - 1, mint + 1, mint + a[mint] - 1) % MOD;
		}
	}
	printf("%d\n", ans %= MOD);
	return 0;
}