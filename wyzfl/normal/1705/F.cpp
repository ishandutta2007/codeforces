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

const int N = 1005;

char biao[10][20] = {
	"000111001111010",
	"011110011101101",
	"101010010001011",
	"111110000110000",
	"100101000001001",
	"100111111010101",
	"110101010101110",
	"001001010000010",
	"111000000001101",
	"000100000000010"
};

map<vector<int>, int> mp;
int a[N], ans[N];
int n, all;

int query() {
	rep(i, 1, n) {
		if (a[i] == 0)
			cout << 'T';
		else
			cout << 'F';
	}
	cout << endl;
	int ans;
	cin >> ans;
	if (ans == n) exit(0);
	return ans;
}

void solve(int l, int r) {
	memset(a, 0, sizeof(a));
	vector<int> now(10);
	for (int i = 0; i < 10; i++) {
		int cnt = 0;
		for (int j = l; j <= r; j++) {
			a[j] = biao[i][j - l] - '0';
			cnt += a[j];
		}
		now[i] = (query() + cnt - all) / 2;
	}
	int st = mp[now];
	for (int i = 0; i < 15; i++) {
		ans[i + l] = ((st >> i) & 1);
	}
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	all = query();
	if (n <= 100) {
		rep(i, 1, n) {
			a[i] ^= 1;
			int tmp = query();
			if (tmp > all) ans[i] = 1;
			a[i] ^= 1;
		}
	} else {
		rep(i, 0, (1 << 15) - 1) {
			vector<int> ans(10);
			rep(j, 1, 10) {
				int cnt = 0;
				rep(k, 1, 15) {
					cnt += (biao[j - 1][k - 1] == '1' && ((i >> (k - 1)) & 1) == 1);
				}
				ans[j - 1] = cnt;
			}
			mp[ans] = i;
		}
		rep(i, 1, (n + 14) / 15) {
			int r = min(n, i * 15), l = r - 14;
			solve(l, r);
		}
	}
	memcpy(a, ans, sizeof(a));
	query();
}