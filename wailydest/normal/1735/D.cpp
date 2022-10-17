#include <cstdio>
#include <set>

const int N = 1000;
const int L = 20;
int n, K, a[N][L];
std::set<long long> st;

int main() {
	scanf("%d%d", &n, &K);
	for (int i = 0; i < n; ++i) {
		long long x = 0, p = 1;
		for (int j = 0; j < K; ++j) {
			scanf("%d", a[i] + j);
			x += a[i][j] * p;
			p *= 3;
		}
		st.insert(x);
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) if (i != j) {
			long long x = 0, p = 1;
			for (int k = 0; k < K; ++k) {
				int cur;
				if (a[i][k] == a[j][k]) cur = a[i][k];
				else cur = (a[i][k] + 1 ^ a[j][k] + 1) - 1;
				x += cur * p;
				p *= 3;
			}
			cnt += st.count(x);
		}
		cnt >>= 1;
		ans += cnt * (cnt - 1) / 2;
	}
	printf("%lld\n", ans);
	return 0;
}