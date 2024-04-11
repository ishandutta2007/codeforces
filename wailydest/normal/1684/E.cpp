#include <cstdio>
#include <map>
#include <algorithm>

const int N = 100005;
int t, n, k, a[N];

struct bit {
	int *b;
	bit() {
		b = new int [N];
	}
	void upd(int i, int d) {
		while (i <= n) {
			b[i] += d;
			i |= i + 1;
		}
	}
	int get(int i) {
		int s = 0;
		while (i >= 0) {
			s += b[i];
			i = (i & i + 1) - 1;
		}
		return s;
	}
} sum, cnt;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		std::map<int, int> mp;
		for (int i = 0; i < n; ++i) {
			sum.b[i] = sum.b[i + 1] = cnt.b[i] = cnt.b[i + 1] = 0;
			scanf("%d", a + i);
			++mp[a[i]];
		}
		for (std::map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
			cnt.upd(it->second, 1);
			sum.upd(it->second, it->second);
		}
		std::sort(a, a + n);
		int take = 0, ans = mp.size();
		for (int i = 0; i < n; ++i) {
			if (mp.count(i)) {
				sum.upd(mp[i], -mp[i]);
				cnt.upd(mp[i], -1);
				mp.erase(i);
			} else ++take;
			if (take <= k) {
				int l = 1, r = n + 1;
				while (l < r) {
					int m = l + r >> 1;
					if (sum.get(m) > take) r = m;
					else l = m + 1;
				}
				int cur;
				if (r == n + 1) cur = mp.size();
				else cur = cnt.get(r - 1) + (take - sum.get(r - 1)) / r;
				ans = std::min(ans, (int)mp.size() - cur);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}