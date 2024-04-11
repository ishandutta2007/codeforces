#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

const int N = 50;
const int M = 500;
int n, m, top[N], k, p, A, B, C;
std::pair<int, long long> ans[M * M];
std::pair<int, std::pair<int, int> > a[M];
std::pair<std::pair<int, bool>, int> e[M];
std::vector<int> pt;

int find(int a) {
	if (top[a] == -1) return a;
	return top[a] = find(top[a]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return 0;
	top[b] = a;
	return 1;
}

long long f(int x) {
	int p = std::upper_bound(pt.begin(), pt.end(), x) - pt.begin();
	return (long long)x * ans[p].first + ans[p].second;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a[i].second.first, &a[i].second.second, &a[i].first);
		--a[i].second.first;
		--a[i].second.second;
	}
	for (int i = 0; i < m; ++i) {
		pt.push_back(a[i].first);
		for (int j = i + 1; j < m; ++j) pt.push_back(a[i].first + a[j].first + 1 >> 1);
	}
	std::sort(pt.begin(), pt.end());
	for (int i = 0; i <= (int)pt.size(); ++i) {
		int cur = i ? pt[i - 1] : -500000000;
		for (int j = 0; j < m; ++j) {
			e[j].first.first = abs(a[j].first - cur);
			e[j].first.second = a[j].first <= cur;
			e[j].second = j;
		}
		std::sort(e, e + m);
		memset(top, -1, N << 2);
		for (int j = 0; j < m; ++j) if (merge(a[e[j].second].second.first, a[e[j].second].second.second)) {
			if (a[e[j].second].first > cur) {
				--ans[i].first;
				ans[i].second += a[e[j].second].first;
			} else {
				++ans[i].first;
				ans[i].second -= a[e[j].second].first;
			}
		}
	}
	scanf("%d%d%d%d%d", &p, &k, &A, &B, &C);
	long long ans = 0;
	int qi, qii;
	for (int i = 0; i < k; ++i) {
		if (i < p) scanf("%d", &qi);
		else qi = ((long long)qii * A + B) % C;
		ans ^= f(qi);
		qii = qi;
	}
	printf("%lld\n", ans);
	return 0;
}