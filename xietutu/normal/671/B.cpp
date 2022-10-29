#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef unsigned int ui;
#define PB push_back
#define MP make_pair
#define F first
#define S second
const int maxn = 500010;
typedef long long LL;
int n, k, minv, maxv, c[maxn];
LL sum, delta;
inline LL cr(int x) {
	LL ret = 0;
	for (int i = 1; i <= n; ++i)
		if (c[i] > x) ret += c[i] - x;
	return ret;
}
inline LL cl(int x) {
	LL ret = 0;
	for (int i = 1; i <= n; ++i)
		if (c[i] < x) ret += x - c[i];
	return ret;
}
int up() {
	int l = minv - 1, r = maxv;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		if (cr(mid) <= k) r = mid;
		else l = mid;
	}
	return r;
}
int down() {
	int l = minv, r = maxv + 1;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		if (cl(mid) <= k) l = mid;
		else r = mid;
	}
	return l;
}
int main() {
	scanf("%d%d", &n, &k);
	minv = 1e9; maxv = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", c + i);
		minv = min(minv, c[i]);
		maxv = max(maxv, c[i]);
		sum += c[i];
	}
	printf("%d\n", max(up() - down(), sum % n != 0 ? 1 : 0));
}