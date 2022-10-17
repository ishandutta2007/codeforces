#include <cstdio>
#include <algorithm>
#include <cstring>

const int A = 26;
const int N = 200000;
int t, n, k, amt[A], amt_[A];
char s[N + 1];

bool test(int l) 
{
	if (l * k > n) return 0;
	memcpy(amt_, amt, A << 2);
	for (int i = 0; i < k; ++i) {
		int ll = l;
		for (int j = 0; j < A; ++j) {
			int tk = std::min(amt_[j] / 2, ll / 2);
			ll -= tk * 2;
			amt_[j] -= tk * 2;
		}
		if (ll > 1) return 0;
		if (ll == 1) {
			int j;
			for (j = 0; j < A && amt_[j] & 1 ^ 1; ++j);
			if (j == A) {
				for (j = 0; j < A && !amt_[j]; ++j);
				if (j == A) return 0;
			}
			--amt_[j];
		}
	}
	return 1;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%s", &n, &k, s);
		memset(amt, 0, A << 2);
		for (int i = 0; i < n; ++i) ++amt[s[i] - 'a'];
		int l = 1, r = n;
		while (l <= r) {
			int m = l + r >> 1;
			if (test(m)) l = m + 1;
			else r = m - 1;
		}
		printf("%d\n", l - 1);
	}
	return 0;
}