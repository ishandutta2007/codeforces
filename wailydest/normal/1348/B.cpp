#include <cstdio>
#include <vector>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d\n", &n, &k);
		bool usd[100] = {0};
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			--a[i];
			usd[a[i]] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) cnt += (int)usd[i];
		if (cnt > k) {
			printf("-1\n");
			continue;
		}
		vector<int> from;
		for (int i = 0; i < n; ++i) if (usd[i]) from.push_back(i);
		while (from.size() < k) from.push_back(0);
		int sz = 0;
		for (int i = 0, j = 0; i < n; ++sz) {
			if (from[j] == a[i]) ++i;
			++j;
			if (j == k) j = 0;
		}
		printf("%d\n", sz);
		for (int i = 0; i < sz; ++i) printf("%d ", from[i % k] + 1);
		printf("\n");
	}
	return 0;
}