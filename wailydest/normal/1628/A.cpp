#include <cstdio>
#include <vector>
#include <cstring>

const int N = 200005;
int t, n, a[N], last[N];
bool u[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(last, -1, n + 1 << 2);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			last[a[i]] = i;
		}
		std::vector<int> ans;
		for (int i = 0; i < n;) {
			if (last[0] < i) {
				ans.push_back(0);
				++i;
			} else {
				int mex = 0, fi = i;
				do {
					while (!u[mex]) {
						u[a[i]] = 1;
						++i;
					}
					++mex;
				} while (u[mex] || last[mex] >= i);
				for (int j = fi; j < i; ++j) u[a[j]] = 0;
				ans.push_back(mex);
			}
		}
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < (int)ans.size(); ++i) printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}