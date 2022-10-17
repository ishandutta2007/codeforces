#include <cstdio>
#include <functional>
#include <algorithm>
#include <vector>

const int N = 200000;
int t, n, u[N];
long long ans[N];
std::vector<long long> in[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", u + i);
		for (int i = 0; i < n; ++i) {
			int v;
			scanf("%d", &v);
			in[u[i] - 1].push_back(v);
		}
		for (int i = 0; i < n; ++i) {
			std::sort(in[i].begin(), in[i].end(), std::greater<int>());
			for (int j = 1; j < in[i].size(); ++j) in[i][j] += in[i][j - 1];
			for (int j = 1; j <= in[i].size(); ++j) {
				for (int k = j; k <= in[i].size(); k += j) ans[j - 1] += in[i][k - 1] - (k == j ? 0 : in[i][k - j - 1]);
			}
		}
		for (int i = 0; i < n; ++i) {
			printf("%lld ", ans[i]);
			ans[i] = 0;
			in[i].clear();
		}
		printf("\n");
	}
	return 0;
}