#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N = 505, Q = 600005;
const long long Bitmask = (1ull << 6) - 1;

struct BigBit {
	unsigned long long bit[8];

	BigBit(const int n = 0) {
		memset(bit, 0, sizeof(bit));
		if (n != -1) bit[n >> 6] = 1ull << (n & Bitmask);
	}
};

bool tobool (const BigBit &a) {
	unsigned long long ret = 0;
	for (int i = 0; i < 8; ++i) ret |= a.bit[i];
	return (bool)ret;
}

BigBit operator | (const BigBit &a, const BigBit &b) {
	BigBit c;
	for (int i = 0; i < 8; ++i) c.bit[i] = a.bit[i] | b.bit[i];
	return c;
}

BigBit operator & (const BigBit &a, const BigBit &b) {
	BigBit c;
	for (int i = 0; i < 8; ++i) c.bit[i] = a.bit[i] & b.bit[i];
	return c;
}

int n, m, r, x1[Q], y1[Q], x2[Q], y2[Q];
char map[N][N];
BigBit p[N][N], q[N][N];
bool ans[Q];

void procdis(const int l, const int r, const int k) {
	for (int i = k; i >= l; --i) {
		for (int j = n; j >= 1; --j) {
			if (map[j][i] == '#') {
				p[j][i] = -1;
			} else {
				if (i == k) {
					p[j][i] = j - 1;
				} else {
					p[j][i] = p[j][i + 1];
				}
				if (j != n) p[j][i] = p[j][i] | p[j + 1][i];
			}
//cout << l << ' ' << r << ' ' << k << ' ' << p[j][i].bit[0] << endl;
		}
	}
	for (int i = k; i <= r; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (map[j][i] == '#') {
				q[j][i] = -1;
			} else {
				if (i == k) {
					q[j][i] = j - 1;
				} else {
					q[j][i] = q[j][i - 1];
				}
				if (j != 1) q[j][i] = q[j][i] | q[j - 1][i];
			}
//cout << l << ' ' << r << ' ' << k << ' ' << q[j][i].bit[0] << endl;
		}
	}
}

bool procans(const int que) {
	return tobool(p[x1[que]][y1[que]] & q[x2[que]][y2[que]]);
}

void divide(const int l, const int r, vector<int> que) {
	int k = (l + r) >> 1;
	procdis(l, r, k);
	vector<int> left, right;
	for (int i = 0; i < que.size(); ++i) {
		if (y2[que[i]] < k) {
			left.push_back(que[i]);
		} else if (y1[que[i]] > k) {
			right.push_back(que[i]);
		} else {
			ans[que[i]] = procans(que[i]);
		}
	}
	if (left.size() > 0) divide(l, k - 1, left);
	if (right.size() > 0) divide(k + 1, r, right);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%s", map[i] + 1);
	scanf("%d", &r);
	vector<int> que;
	for (int i = 1; i <= r; ++i) {
		ans[i] = false;
		scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
		if (x2[i] >= x1[i] && y2[i] >= y1[i]) que.push_back(i);
	}
	divide(1, m, que);
	for (int i = 1; i <= r; ++i) {
		printf("%s\n", ans[i] ? "Yes" : "No");
	}
	return 0;
}