#include <cstdio>
#include <vector>

const int N = 100005;
const int LG = 17;
int n, q, ps[N], sum[N];
std::vector<int> num[N];

int main() {
	scanf("%d%d", &n, &q);
	int need = n;
	for (int i = 1; need; ++i) {
		int amt = (i - 1) / 2 + 1;
		if (need > amt) {
			need -= amt;
		} else {
			for (int j = N - 1; j >= 0; --j) {
				if (j + 1 <= i - 1 + (bool)need) {
					num[j].push_back(1);
					need -= j + 1 == i;
				}
				for (int k = j + 1;; ++k) {
					int amt = i - 2 + (bool)need - j - (1 << k - j);
					if (amt >= 0) amt = amt / 2 + 1;
					else amt = 0;
					amt = std::min(amt, 1 << k - j - 1);
					if (amt) num[j].push_back(amt);
					else break;
					need -= (1 << k - j) + (amt - 1) * 2 + 1 + j == i;
				}
			}
		}
	}
	long long total = 0;
	for (int i = 0; i + 1 < N; ++i) {
		for (int j = 0; j < num[i].size(); ++j) {
			sum[i + j + 1] += num[i][j];
			total += (long long)num[i][j] * ((1 << j) + (bool)j + num[i][j] - 1 + i);
		}
	}
	for (int i = 1; i < N; ++i) sum[i] += sum[i - 1];
	printf("%lld\n", total);
	while (q--) {
		int ind;
		scanf("%d", &ind);
		--ind;
		int pos = 0;
		for (int i = LG - 1; i >= 0; --i) if (sum[pos | 1 << i] <= ind) pos |= 1 << i;
		ind -= sum[pos];
		if (!ind) printf("%d\n", pos + 1);
		else {
			--ind;
			int l = 0, r = 1 << LG + 1;
			while (l < r) {
				int m = l + r >> 1, cnt = 0;
				for (int i = pos - 1; i >= 0 && num[i].size() + i > pos; --i) {
					int p = 1 << LG - pos + i;
					if (p <= m) cnt += std::min(num[i][pos - i], (m - p) / (p * 2) + 1);
				}
				if (cnt > ind) r = m;
				else l = m + 1;
			}
			int lg = __builtin_ctz(r);
			r += 1 << LG;
			r >>= lg;
			printf("%d\n", r + pos - LG + lg);
		}
	}
	return 0;
}