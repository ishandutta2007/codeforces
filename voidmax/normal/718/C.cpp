#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = a; i < b; ++i)
#define forl(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <base, base>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)
using namespace std;

typedef long long base;
const base P = 1e9 + 7;

struct matrix {
	base arr[2][2];
	matrix() {
		forr(i, 0, 2)
			forr(j, 0, 2) 
				arr[i][j] = 0;
	}
	matrix(pair <point, point> m) {
		arr[0][0] = m.x.x;
		arr[0][1] = m.x.y;
		arr[1][0] = m.y.x;
		arr[1][1] = m.y.y;
	}
};

inline base sum(base a, base b) {
	a += b;
	if (a >= P)
		a -= P;
	return a;
}

inline base mul(base a, base b) {
	return (a * b) % P;
}

matrix operator *(matrix a, matrix b) {
	matrix c;
	forr(i, 0, 2) {
		forr(j, 0, 2) {
			forr(k, 0, 2) {
				c.arr[i][j] = sum(c.arr[i][j], mul(a.arr[i][k], b.arr[k][j]));
			}
		}
	}
	return c;
}

matrix operator +(matrix a, matrix b) {
	forr(i, 0, 2) {
		forr(j, 0, 2) {
			a.arr[i][j] = sum(a.arr[i][j], b.arr[i][j]);
		}
	}
	return a;
}

const matrix ONE = matrix({{1, 0}, {0, 1}});
const matrix FIB = matrix({{0, 1}, {1, 1}});

matrix operator ^(matrix a, base j) {
	matrix ans = ONE;
	while (j) {
		if (j & 1) ans = ans * a;
		a = a * a;
		j >>= 1;
	}
	return ans;
}

int m;

struct seg_tree {
	int n;
	vector <matrix> s;
	vector <matrix> m;
	seg_tree() {};
	void build() {
		int k;
		cin >> k >> ::m;
		n = 1;
		while (n < k) n <<= 1;
		s.resize(n * 2, ONE);
		m.resize(n * 2, ONE);
		forr(i, 0, k) {
			int a;
			cin >> a;
			m[i + n] = FIB ^ (a - 1);
		}
		forl(i, n, 1) s[i] = s[i * 2] * m[i * 2] + s[i * 2 + 1] * m[i * 2 + 1];
	}
	void change(int i, int L, int R, int Ln, int Rn, matrix N) {
		if (Ln <= L && R <= Rn) {
			m[i] = m[i] * N;
			return;
		}
		if (R <= Ln || Rn <= L) {
			return;
		}
		int M = (L + R) >> 1;
		change(i * 2, L, M, Ln, Rn, N);
		change(i * 2 + 1, M, R, Ln, Rn, N);
		s[i] = s[i * 2] * m[i * 2] + s[i * 2 + 1] * m[i * 2 + 1];
	} 
	void changeg(int L, int R, matrix N) {
		change(1, 0, n, L, R, N);
	}
	matrix get(int i, int L, int R, int Ln, int Rn) {
		if (Ln <= L && R <= Rn) {
			return s[i] * m[i];
		}
		if (R <= Ln || Rn <= L) {
			return matrix();
		}
		int M = (L + R) >> 1;
		return (get(i * 2, L, M, Ln, Rn) + 
				get(i * 2 + 1, M, R, Ln, Rn)) * m[i];
	}
	matrix getg(int L, int R) {
		return get(1, 0, n, L, R);
	}
};

seg_tree arr;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(0);
	arr.build();
	forr(i, 0, m) {
		int t, L, R, X;
		cin >> t >> L >> R;
		if (t == 1) {
			cin >> X;
			arr.changeg(L - 1, R, FIB ^ X);
		} else {
			auto ans = arr.getg(L - 1, R);
			cout << ans.arr[1][1] << endl;
		}
	}
}