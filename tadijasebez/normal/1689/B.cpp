#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int p[N], ans[N];

int main() {
	int tc;
	scanf("%i",&tc);
	while (tc--) {
		int n;
		scanf("%i", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%i", &p[i]);
		if (n == 1) {
			printf("-1\n");
			continue;
		}
		set<int> cand;
		for (int i = 1; i <= n; ++i)
			cand.insert(i);
		for (int i = 1; i <= n; ++i) {
			auto it = cand.begin();
			if (i != n && *it == p[i])
				it++;
			//if (i == n - 1 && *cand.rbegin() == p[n])
			//	it++;
			//printf("%i ",*it);
			ans[i] = *it;
			cand.erase(it);
		}
		if (ans[n] == p[n])
			swap(ans[n - 1], ans[n]);
		for (int i = 1; i <= n; ++i)
			printf("%i ",ans[i]);
		printf("\n");
	}
    return 0;
}