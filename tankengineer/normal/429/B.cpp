#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;

int n, m, a[N][N];

int f11[N][N][2], fn1[N][N][2], tnm[N][N][2], t1m[N][N][2];

const int INF = 1000000000;

void update(int &a, int b) {
	a = max(a, b);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < 2; ++k) {
				f11[i][j][k] = fn1[i][j][k] = tnm[i][j][k] = t1m[i][j][k] = -INF;
			}
		}
	}
	f11[0][0][0] = f11[0][0][1] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < 2; ++k) {
				if (f11[i][j][k] < 0) {
					continue;
				}
				if (i + 1 < n) {
					update(f11[i + 1][j][0], f11[i][j][k] + a[i][j]);
				}
				if (j + 1 < m) {
					update(f11[i][j + 1][1], f11[i][j][k] + a[i][j]);
				}
			}
		}
	}
	fn1[n - 1][0][0] = fn1[n - 1][0][1] = 0;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < 2; ++k) {
				if (fn1[i][j][k] < 0) {
					continue;
				}
				if (i - 1 >= 0) {
					update(fn1[i - 1][j][0], fn1[i][j][k] + a[i][j]);
				}
				if (j + 1 < m) {
					update(fn1[i][j + 1][1], fn1[i][j][k] + a[i][j]);
				}
			}
		}
	}
	t1m[0][m - 1][0] = t1m[0][m - 1][1] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = m - 1; j >= 0; --j) {
			for (int k = 0; k < 2; ++k) {
				if (t1m[i][j][k] < 0) {
					continue;
				}
				if (i + 1 < n) {
					update(t1m[i + 1][j][0], t1m[i][j][k] + a[i][j]);
				}
				if (j - 1 >= 0) {
					update(t1m[i][j - 1][1], t1m[i][j][k] + a[i][j]);
				}
			}
		}
	}
	tnm[n - 1][m - 1][0] = tnm[n - 1][m - 1][1] = 0;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			for (int k = 0; k < 2; ++k) {
				if (tnm[i][j][k] < 0) {
					continue;
				}
				if (i - 1 >= 0) {
					update(tnm[i - 1][j][0], tnm[i][j][k] + a[i][j]);
				}
				if (j - 1 >= 0) {
					update(tnm[i][j - 1][1], tnm[i][j][k] + a[i][j]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int in1 = 0; in1 < 2; ++in1) {
				for (int in2 = 0; in2 < 2; ++in2) {
					if (in1 == in2) {
						continue;
					}
					for (int out1 = 0; out1 < 2; ++out1) {
						for (int out2 = 0; out2 < 2; ++out2) {
							if (out1 && out2) {
								continue;
							}
							if (in1 == out2) {
								continue;
							}
							if (in2 == out1) {
								continue;
							}
							int tmp = f11[i][j][in1] + fn1[i][j][in2] + tnm[i][j][out1] + t1m[i][j][out2];
							if (tmp > ans) {
								//cout << i << ' ' << j << ' ' << in1 << ' ' << in2 << ' ' << out1 << ' ' << out2 << endl;
//cout << f11[i][j][in1] << ' ' << fn1[i][j][in2] << ' ' << tnm[i][j][out1] << ' ' << t1m[i][j][out2] << endl;
								ans = tmp;
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}