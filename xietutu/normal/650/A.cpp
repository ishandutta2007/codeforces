#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;
typedef long long ll;
const int maxn = 200010;
pii a[maxn];
ll ans;
int n;
bool cmpx(pii a, pii b) {
	return a.X < b.X;
}
bool cmpy(pii a, pii b) {
	return a.Y < b.Y;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i].X, &a[i].Y);
	
	sort(a, a + n, cmpx);
	for (int i = 0; i < n; ++i) {
		int r = i;
		while (r + 1 < n && a[r + 1].X == a[i].X) ++r;
		ans += 1LL * (r - i + 1) * (r - i) / 2;
		i = r;
	}
	
	sort(a, a + n, cmpy);
	for (int i = 0; i < n; ++i) {
		int r = i;
		while (r + 1 < n && a[r + 1].Y == a[i].Y) ++r;
		ans += 1LL * (r - i + 1) * (r - i) / 2;
		i = r;
	}
	
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		int r = i;
		while (r + 1 < n && a[r + 1] == a[i]) ++r;
		ans -= 1LL * (r - i + 1) * (r - i) / 2;
		i = r;
	}
	cout << ans << endl;
}