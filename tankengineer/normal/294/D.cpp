#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

int n, m, sx, sy, dx, dy, NumBorder;
long long ans;
set<pair<int, int> > memory;

void prepare() {
	char ts[5];	
	scanf("%d %d", &n, &m);
	scanf("%d %d %s", &sx, &sy, ts);
	if (ts[0] == 'D') dx = 1; else dx = -1;
	if (ts[1] == 'R') dy = 1; else dy = -1;
	NumBorder = 0;
	for (int i = 1; i <= m; ++i) {
		if ((1 + i) % 2 == (sx + sy) % 2) ++NumBorder;	
		if (n > 1 && (n + i) % 2 == (sx + sy) % 2) ++ NumBorder;
	}
	for (int i = 2; i < n; ++i) {
		if ((1 + i) % 2 == (sx + sy) % 2) ++NumBorder;
		if (m > 1 && (m + i) % 2 == (sx + sy) % 2) ++ NumBorder;
	}
}

bool isfull() {
	return memory.size() == NumBorder;
}

void remember() {
	memory.insert(make_pair(sx, sy));
}

bool inmap(const int tx, const int ty) {
	return tx >= 1 && tx <= n && ty >= 1 && ty <= m;
}

void gonext() {
	int l = 0, r = n + m, mid;
	while (r > l) {
		mid = (l + r) >> 1;
		if (inmap(sx + dx * mid, sy + dy * mid)) l = mid + 1; else r = mid;
	}
	int step = l - 1;
	ans += step;
	sx += step * dx;
	sy += step * dy;
	if (sx == 1) dx = 1;
	if (sx == n) dx = -1;
	if (sy == 1) dy = 1;
	if (sy == m) dy = -1;
	remember();
}

int main() {
	prepare();
	remember();
	ans = 1;
	int BAR = (n + m) * 4;
	while (BAR--) {
//cout << sx << ' ' << sy << ' ' << dx << ' ' << dy << endl;			
		if (isfull()) {
			cout << ans << endl;
			return 0;
		}
		gonext();
	}
	printf("-1\n");
	return 0;
}