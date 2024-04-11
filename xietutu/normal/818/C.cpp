#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef unsigned int ui;
#define PB push_back
#define MP make_pair
#define X first
#define Y second
const int maxn = 100010;
int d, n, m;
vector<int> x[maxn], y[maxn];
pii a[maxn][2];
int cntl_, cntr_, cntt_, cntb_;
int now[maxn], cntl[maxn], cntr[maxn], cntt[maxn], cntb[maxn];
set<int> T;
void prepare() {
	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		for (auto v : x[i]) {
			cntl[v] = ret - T.count(v);	
		}
		for (auto v : x[i]) {
			if (!T.count(v)) {
				T.insert(v);
				++ret;
			}
		}
	}
	
	ret = 0;
	T.clear();
	for (int i = n; i >= 1; --i) {
		for (auto v : x[i]) {
			cntr[v] = ret - T.count(v);	
		}
		for (auto v : x[i]) {
			if (!T.count(v)) {
				T.insert(v);
				++ret;
			}
		}
	}
	
	ret = 0;
	T.clear();
	for (int i = m; i >= 1; --i) {
		for (auto v : y[i]) {
			cntb[v] = ret - T.count(v);	
		}
		for (auto v : y[i]) {
			if (!T.count(v)) {
				T.insert(v);
				++ret;
			}
		}
	}
	
	ret = 0;
	T.clear();
	for (int i = 1; i <= m; ++i) {
		for (auto v : y[i]) {
			cntt[v] = ret - T.count(v);	
		}
		for (auto v : y[i]) {
			if (!T.count(v)) {
				T.insert(v);
				++ret;
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &d, &n, &m);
	for (int i = 1; i <= d; ++i) {
		for (int j = 0; j < 2; ++j) {
			scanf("%d%d", &a[i][j].X, &a[i][j].Y);
		}
		x[a[i][0].X].PB(i);
		x[a[i][1].X].PB(i);
		
		y[a[i][0].Y].PB(i);
		y[a[i][1].Y].PB(i);
	}
	
	prepare();
	int ans = -1;
	scanf("%d%d%d%d", &cntl_, &cntr_, &cntt_, &cntb_);
	for (int i = 1; i <= d; ++i) {
		if (cntl[i] == cntl_ && cntr[i] == cntr_ && cntt[i] == cntt_ && cntb[i] == cntb_) {
			ans = i;
		}
	}
	cout << ans << endl;
}