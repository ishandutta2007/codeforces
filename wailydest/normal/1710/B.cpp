#include <cstdio>
#include <set>
#include <utility>
#include <algorithm>

const int N = 200005;
int t, n, m, pos[N];
long long mxpref[N], mxsuf[N];
long long res[N];

struct item {
	int first, second, ind;
} a[N];

bool operator<(item a, item b) {
	return a.first < b.first;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i].first, &a[i].second);
			a[i].ind = i;
		}
		std::sort(a, a + n);
		std::multiset<int> st;
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			pos[a[i].ind] = i;
			while (!st.empty() && *st.begin() <= a[i].first) {
				sum -= *st.begin();
				st.erase(st.begin());
			}
			res[i] = sum - (long long)st.size() * a[i].first;
			sum += a[i].first + a[i].second;
			st.insert(a[i].first + a[i].second);
		}
		st.clear();
		sum = 0;
		mxpref[0] = mxsuf[n] = (long long)1 << 63;
		for (int i = n - 1; i >= 0; --i) {
			while (!st.empty() && *(--st.end()) >= a[i].first) {
				sum -= *(--st.end());
				st.erase(--st.end());
			}
			sum += a[i].first - a[i].second;
			st.insert(a[i].first - a[i].second);
			res[i] += (long long)a[i].first * st.size() - sum;
			mxsuf[i] = mxsuf[i + 1];
			if (res[i] > m) mxsuf[i] = std::max(mxsuf[i], res[i] - m + a[i].first);
		}
		for (int i = 0; i < n; ++i) {
			mxpref[i + 1] = mxpref[i];
			if (res[i] > m) mxpref[i + 1] = std::max(mxpref[i + 1], res[i] - m - a[i].first);
		}
		for (int i = 0; i < n; ++i) {
			int ind = pos[i];
			if (mxpref[ind] <= a[ind].second - a[ind].first && mxsuf[ind] <= a[ind].second + a[ind].first) printf("1");
			else printf("0");
		}
		printf("\n");
	}
	return 0;
}