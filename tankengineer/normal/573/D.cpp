#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 30005;

int n, q;

int a[N], b[N], orda[N], ordb[N], ban[N], rnk[N];

bool byA(const int &i, const int &j) {
	return a[i] < a[j] || (a[i] == a[j] && i < j);
}

bool byB(const int &i, const int &j) {
	return b[i] < b[j] || (b[i] == b[j] && i < j);
}

const long long INF = 1ll << 60;

long long dp[N];

inline long long cost(const int &i, const int &j) {
	return ban[orda[i]] == ordb[j] ? -INF : (long long)a[orda[i]] * b[ordb[j]];
}

struct Matrix {
	long long a[3][3];

	Matrix() {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				a[i][j] = -INF;
			}
		}
	}

	const long long* operator[] (const int &i) const {
		return a[i];
	}

	long long* operator[] (int i) {
		return a[i];
	}
};

Matrix operator * (const Matrix &a, const Matrix &b) {
	Matrix ret;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				ret[i][j] = max(ret[i][j], a[i][k] + b[k][j]);
			}
		}
	}
	return ret;
}

Matrix getMatrix(int pos) {
	Matrix ret;
	ret[0][0] = cost(pos, pos);
	if (pos + 1 < n) {
		ret[0][1] = cost(pos, pos + 1) + cost(pos + 1, pos);
		if (pos + 2 < n) {
			ret[0][2] = max(cost(pos, pos + 2) + cost(pos + 1, pos) + cost(pos + 2, pos + 1), cost(pos, pos + 1) + cost(pos + 1, pos + 2) + cost(pos + 2, pos));
		}
	}
	ret[1][0] = 0;
	ret[2][1] = 0;
	return ret;
}

Matrix tr[N << 1];

inline int getID(int l, int r) {
	return l + r | l != r;
}

void update(int l, int r) {
	int m = l + r >> 1, x = getID(l, r), lc = getID(l, m), rc = getID(m + 1, r);
	tr[x] = tr[lc] * tr[rc];
}

void init(int l, int r) {
	if (l == r) {
		tr[getID(l, r)] = getMatrix(l);
		return;
	}
	int m = l + r >> 1;
	init(l, m);
	init(m + 1, r);
	update(l, r);	
}

void recal(int l, int r, int a, int b) {
	if (l == r) {
		tr[getID(l, r)] = getMatrix(l);
		return;
	}
	int m = l + r >> 1;
	if (a <= m) {
		recal(l, m, a, b);
	}
	if (b > m) {
		recal(m + 1, r, a, b);
	}
	update(l, r);
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		orda[i] = i;
	}
	sort(orda, orda + n, byA);
	for (int i = 0; i < n; ++i) {
		rnk[orda[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", b + i);
		ordb[i] = i;
	}
	sort(ordb, ordb + n, byB);
	for (int i = 0; i < n; ++i) {
		ban[i] = i;
	}
	init(0, n - 1);
	while (q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		swap(ban[u], ban[v]);
		recal(0, n - 1, max(0, rnk[u] - 2), rnk[u]);
		recal(0, n - 1, max(0, rnk[v] - 2), rnk[v]);
		cout << tr[getID(0, n - 1)][0][0] << endl;
		/*
		for (int i = 0; i <= n; ++i) {
			dp[i] = -INF;
		}
		dp[0] = 0;
		for (int i = 0; i < n; ++i) {
			dp[i + 1] = max(dp[i + 1], dp[i] + cost(i, i));
			if (i + 1 < n) {
				dp[i + 2] = max(dp[i + 2], dp[i] + cost(i, i + 1) + cost(i + 1, i));
				if (i + 2 < n) {
					dp[i + 3] = max(dp[i + 3], dp[i] + cost(i, i + 2) + cost(i + 1, i) + cost(i + 2, i + 1));
					dp[i + 3] = max(dp[i + 3], dp[i] + cost(i, i + 1) + cost(i + 1, i + 2) + cost(i + 2, i));
				}
			}
		}
		*/
	}
	return 0;
}