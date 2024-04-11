#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
#undef gc

const int N = 2e5 + 5;

vector<int> vec[N];
int st[N][18], lg[N], f[N], t[N];
int T, n, m, q;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int query(int l, int r) {
	int k = lg[r - l + 1];
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		m = read();
		q = read();
		rep(i, 1, n) f[i] = i, vec[i].clear(), vec[i].push_back(i);
		rep(i, 1, m) {
			int u = read(), v = read();
			int x = find(u), y = find(v);
			if (x != y) {
				if (vec[x].size() > vec[y].size()) swap(x, y);
				for (auto j: vec[x]) {
					if (j != 1 && find(j - 1) == y) t[j - 1] = i;
					if (j != n && find(j + 1) == y) t[j] = i;
					vec[y].push_back(j);
				}
				f[x] = y;
			}
		}
		lg[0] = -1;
		rep(i, 1, n) lg[i] = lg[i >> 1] + 1, st[i][0] = t[i];
		rep(j, 1, 17) {
			rep(i, 1, n - (1 << j) + 1) {
				st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
			}
		}
		rep(i, 1, q) {
			int l = read(), r = read();
			if (l == r) {
				printf("0%c", i == q ? '\n' : ' ');
			} else {
				printf("%d%c", query(l, r - 1), i == q ? '\n' : ' ');
			}
		}
	}
}