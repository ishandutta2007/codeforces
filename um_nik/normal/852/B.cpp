#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int mult(int x, int y) {
	return ((ll)x * y) % MOD;
}

const int N = 101;
int n;

struct Matrix {
	int a[N][N];

	Matrix() {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = (int)(i == j);
	}
	Matrix operator * (const Matrix &A) const {
		Matrix R = Matrix();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				R.a[i][j] = 0;
				for (int h = 0; h < n; h++)
					R.a[i][j] = add(R.a[i][j], mult(a[i][h], A.a[h][j]));
			}
		return R;
	}
};

Matrix bin_pow(Matrix A, int p) {
	if (p == 0) return Matrix();
	if (p & 1) return A * bin_pow(A, p - 1);
	return bin_pow(A * A, p / 2);
}

const int S = (int)1e6 + 7;
int w[S];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int m, k;
	scanf("%d%d%d", &m, &k, &n);
	Matrix A, B, C;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A.a[i][j] = B.a[i][j] = C.a[i][j] = 0;
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		for (int j = 0; j < n; j++)
			A.a[j][(j + x) % n]++;
	}
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		w[i] = x;
		for (int j = 0; j < n; j++)
			B.a[j][(j + x) % n]++;
	}
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		x += w[i];
		for (int j = 0; j < n; j++)
			C.a[j][(j + x) % n]++;
	}
	A = A * bin_pow(B, k - 2) * C;
	printf("%d\n", A.a[0][0]);

	return 0;
}