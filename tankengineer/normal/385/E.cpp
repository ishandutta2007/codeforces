#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

long long n;

struct Matrix {
	long long num[6][6];

	Matrix(int tag = 0) {
		memset(num, 0, sizeof(num));
		if (tag) {
			for (int i = 0; i < 6; ++i) {
				num[i][i] = 1;
			}
		}
	}
	
	long long * operator[] (int i) {
		return num[i];
	}
};

Matrix operator * (Matrix &a, Matrix &b) {
	Matrix ret;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			for (int k = 0; k < 6; ++k) {
				(ret[i][j] += a[i][k] * b[k][j] % n) %= n;
			}
		}
	}
	return ret;
}

int main() {
	long long sx, sy, dx, dy, t;
	cin >> n >> sx >> sy >> dx >> dy >> t;
	Matrix f, a(1);
	f[0][0] = 2; f[0][1] = 1; f[0][2] = 1; f[0][3] = 1;
	f[1][0] = 1; f[1][1] = 2; f[1][2] = 1; f[1][3] = 1;
	f[2][0] = 1;              f[2][2] = 1;
	             f[3][1] = 1;              f[3][3] = 1;
	f[4][0] = 1; f[4][1] = 1; f[4][2] = 1; f[4][3] = 1; f[4][4] = 1;	
	f[5][0] = 2; f[5][1] = 2; f[5][2] = 2; f[5][3] = 2; f[5][4] = 1; f[5][5] = 1;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			f[i][j] %= n;
		}
	}
	for (int i = 63; i >= 0; --i) {
		a = a * a;
		if ((t >> i) & 1ll) {
			a = a * f;
		}
	}
	long long v[6], u[6];
	v[0] = sx - 1, v[1] = sy - 1, v[2] = (dx % n + n) % n, v[3] = (dy % n + n) % n, v[4] = 0, v[5] = 1;
	memset(u, 0, sizeof(u));
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			(u[j] += v[i] * a[i][j] % n) %= n;
		}
	}
if (u[4] != t % n) {
	while (true) {
		int i = 1;
		continue;
	}
}
	cout << u[0] + 1 << ' ' << u[1] + 1 << endl;
	return 0;
}