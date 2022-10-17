#include <cstdio>
#include <algorithm>

const int N = 200005;
int t, n, le[N], ri[N];
std::pair<int, int> a[N];
bool u[N];

struct tree {
	long long *t;
	tree() {
		t = new long long [N * 2];
	}
	void build() {
		for (int i = n; i > 0; --i) t[i] = std::max(t[i << 1], t[i << 1 | 1]);
	}
	long long query(int l, int r) {
		long long mx = (long long)1 << 63;
		for (l += n + 1, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) mx = std::max(mx, t[l++]);
			if (r & 1) mx = std::max(mx, t[--r]);
		}
		return mx;
	}
} t1, t0;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		long long sum = 0;
		t1.t[n + 1] = t0.t[n + 1] = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i - 1].first);
			sum += a[i - 1].first;
			a[i - 1].second = i - 1;
			t1.t[n + 1 + i] = sum;
			t0.t[n + 1 + i] = -sum;
			u[i - 1] = 0;
		}
		t1.build();
		t0.build();
		std::sort(a, a + n);
		bool ok = 1;
		for (int i = 0; i < n; ++i) {
			int id = a[i].second;
			u[id] = 1;
			int ll = id, rr = id;
			if (id && u[id - 1]) ll = le[id - 1];
			if (id + 1 < n && u[id + 1]) rr = ri[id + 1];
			ri[ll] = rr;
			le[rr] = ll;
			if (t1.query(id + 1, rr + 2) + t0.query(ll, id + 1) > a[i].first) ok = 0;
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}