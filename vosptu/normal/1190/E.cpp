#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;
int n, m;
struct Int {
	double l, r;
} a[N], b[N];
int x[N], y[N];
int Nextm[N], Next[N], pre[N];

bool cmp(Int a, Int b) {
	return a.l < b.l;
}

bool ok(double R) {
	for (int i = 1; i <= n; i++) {
		double angle = acos(R / sqrt(1LL * x[i] * x[i] + 1LL * y[i] * y[i]));
		double mid = atan2(y[i], x[i]);
		a[i].l = mid - angle;
		a[i].r = mid + angle;
		while (a[i].l < 0) {
			a[i].l += 2 * pi;
			a[i].r += 2 * pi;
		}
	}
	sort(a + 1, a + n + 1, cmp);
	int len = 0;

	double minR = 1e9;
	for (int i = 1; i <= n; i++)
		minR = min(minR, a[i].r + 2 * pi);

	for (int i = n; i >= 1; i--) {
		if (minR < a[i].r)
			continue;
		len++;
		b[len] = a[i];
		minR = a[i].r;
	}
	for (int i = 1; i <= len - i + 1; i++)
		swap(b[i], b[len - i + 1]);

	for (int i = len + 1; i <= 2 * len; i++) {
		b[i] = b[i - len];
		b[i].l += 2 * pi;
		b[i].r += 2 * pi;
	}
	int now = 1;
	for (int i = 1; i <= 2 * len; i++) {
		while (now <= 2 * len && b[now].l <= b[i].r)
			now++;
		Next[i] = now;
	}
	Next[2 * len + 1] = 2 * len + 1;

	for (int i = 1; i <= 2 * len + 1; i++)
		Nextm[i] = i;
	for (int i = 20; i >= 0; i--) {
		for (int j = 1; j <= 2 * len + 1; j++)
			Nextm[j] = Nextm[Nextm[j]];
		if (m & (1 << i)) {
			for (int j = 1; j <= 2 * len + 1; j++)
			Nextm[j] = Nextm[Next[j]];
		}
	}

	for (int i = 1; i <= len; i++)
		if (Nextm[i] >= i + len) {
			return true;
		}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	long long min_dist = 1e18;
	set <pair<int, int>> used;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		if (used.count(make_pair(x[i], y[i]))) {
			n--;
			i--;	
			continue;
		}
		used.insert(make_pair(x[i], y[i]));
		min_dist = min(min_dist, 1LL * x[i] * x[i] + 1LL * y[i] * y[i]);
	}
	if (min_dist == 0) {
		printf("0\n");
		return 0;
	}
	double l = 0, r = sqrt(min_dist);
	for (int i = 1; i <= 100; i++) {
		double mid = (l + r) / 2;
		if (ok(mid))
			l = mid;
		else
			r = mid;
	}
	printf("%.10lf\n", (double)((l + r) / 2));
}