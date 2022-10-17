#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 100000;
const int K = 400;
int n, a[N], b[N], amt[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	int ans = 1;
	for (int i = -K; i <= K; ++i) {
		for (int j = 0; j < n; ++j) b[j] = a[j] - j * i;
		std::sort(b, b + n);
		for (int j = 0; j < n;) {
			int amt = 0;
			do {
				++j;
				++amt;
			} while (j < n && b[j] == b[j - 1]);
			ans = std::max(ans, amt);
		}
	}
	if (ans < K) {
		for (int i = 0; i < n; i += K) {
			std::vector<int> vec;
			int until = std::min(n, i + 2 * K);
			for (int j = i; j < until; ++j) {
				for (int k = j + 1; k < until; ++k) if (!((a[k] - a[j]) % (k - j))) vec.push_back((a[k] - a[j]) / (k - j));
				std::sort(vec.begin(), vec.end());
				for (int k = 0; k < (int)vec.size();) {
					int amt = 0;
					do {
						++k;
						++amt;
					} while (k < (int)vec.size() && vec[k] == vec[k - 1]);
					ans = std::max(ans, amt + 1);
				}
				vec.clear();
			}
		}
	}
	printf("%d\n", n - ans);
	return 0;
}