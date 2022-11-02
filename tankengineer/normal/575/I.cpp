#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

const int N = 100000 + 10;
const int M = 5000 + 10;

struct Data
{
	int x, y, comp, tp, id;
	Data() {}
	Data(int x, int y, int comp, int tp, int id) : x(x), y(y), comp(comp), tp(tp), id(id) {}
	int operator < (const Data &that) const {
		return comp > that.comp || (comp == that.comp && tp < that.tp);
	}
};

int n, q, tot;
int x[N], y[N], dir[N], len[N];
int ret[N];
Data a[N];
int flag;
int bit[M][M];
int tag[M][M];

void insert(int x, int y)
{
	for( ; x <= n; x += x & -x) {
		for(int ty = y; ty <= n; ty += ty & -ty) {
			if (tag[x][ty] != flag) {
				tag[x][ty] = flag;
				bit[x][ty] = 0;
			}
			bit[x][ty] ++;
		}
	}
}

int query(int x, int y)
{
	int ret = 0;
	for( ; x; x -= x & -x) {
		for(int ty = y; ty; ty -= ty & -ty) {
			if (tag[x][ty] != flag) {
				tag[x][ty] = flag;
				bit[x][ty] = 0;
			}
			ret += bit[x][ty];
		}
	}
	return ret;
}

void solve(int l, int r)
{
	if (l >= r) return;
	int mid = (l + r) >> 1;
	solve(l, mid); solve(mid + 1, r);
	int cnt0 = 0, cnt1 = 0;
	vector<Data> vec;
	for(int i = l; i <= mid; ++ i) {
		if (a[i].tp == 0) {
			++ cnt0;
			vec.push_back(a[i]);
		}
	}
	for(int i = mid + 1; i <= r; ++ i) {
		if (a[i].tp == 1) {
			++ cnt1;
			vec.push_back(a[i]);
		}
	}
	if (cnt0 == 0 || cnt1 == 0) return;
	sort(vec.begin(), vec.end());
	flag ++;
	for(int i = 0; i < vec.size(); ++ i) {
		if (vec[i].tp == 0) {
			insert(vec[i].x, vec[i].y);
		} else {
			ret[vec[i].id] += query(vec[i].x, vec[i].y);
		}
	}
}

void calcAns(int state)
{
	tot = 0;

	for(int i = 0; i < q; ++ i) {
		int curX = (state & 2) ? n + 1 - x[i] : x[i];
		int curY = (state & 1) ? n + 1 - y[i] : y[i];
		if (curX < 1 || curX > n || curY < 1 || curY > n) continue;
		if (dir[i] < 0) {
			a[tot ++] = Data(curX, curY, curX + curY, 1, i);
		}
		if (dir[i] == state) {
			a[tot ++] = Data(curX, curY, curX + curY + len[i], 0, i);
		}
	}

	solve(0, tot - 1);
}

void solve()
{
	cin >> n >> q;
	int tp;
	for(int i = 0; i < q; ++ i) {
		scanf("%d", &tp);
		if (tp == 2) {
			dir[i] = -1;
			scanf("%d%d", x + i, y + i);
		} else {
			scanf("%d%d%d%d", dir + i, x + i, y + i, len + i);
			dir[i] --;
		}
	}
	for(int i = 0; i < 4; ++ i) {
		calcAns(i);
	}
	for(int i = 0; i < q; ++ i) {
		if (dir[i] < 0) {
			printf("%d\n", ret[i]);
		}
	}
}

int main()
{
	solve();
	return 0;
}