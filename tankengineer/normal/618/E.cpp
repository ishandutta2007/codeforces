#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const double PI = acos(-1);

struct Vector {
	double a[3];

	Vector(const double &x = 0, const double &y = 0, const double &z = 0) {
		a[0] = x, a[1] = y, a[2] = z;
	}

	double len() const {
		return sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	}

	Vector unit(double r) const {
		double l = r / len();
		return Vector(a[0] * l, a[1] * l, a[2] * l);
	}

	const double operator [] (const int &i) const {
		return a[i];
	}

	double& operator [] (const int &i) {
		return a[i];
	}
};

Vector operator - (const Vector &a) {
	return Vector(-a[0], -a[1], -a[2]);
}

Vector operator - (const Vector &a, const Vector &b) {
	return Vector(a[0] - b[0], a[1] - b[1], a[2] - b[2]);
}

Vector operator + (const Vector &a, const Vector &b) {
	return Vector(a[0] + b[0], a[1] + b[1], a[2] + b[2]);
}

inline int sign(double x, double eps = 1e-9) {
	return x < -eps ? -1 : x > eps;
}

struct Matrix {
	double a[4][4];

	Matrix(int type = 0) {
		memset(a, 0, sizeof(a));
		if (type) {
			for (int i = 0; i < 4; ++i) {
				a[i][i] = 1;
			}
		}
	}

	void clear(int type = 0) {
		memset(a, 0, sizeof(a));
		if (type) {
			for (int i = 0; i < 4; ++i) {
				a[i][i] = 1;
			}
		}
	}

	bool checkI() const {
		for (int i = 0; i <= 3; ++i) {
			for (int j = 0; j <= 3; ++j) {
				if ((i == j && sign(a[i][j] - 1) != 0) || ((i != j) && sign(a[i][j]) != 0)) {
					return false;
				}
			}
		}
		return true;
	}

	const double* operator [] (const int &i) const {
		return a[i];
	}

	double* operator[] (const int &i) { 
		return a[i];
	}
};

/*
Vector operator * (const Vector &p, const Matrix &a) {
	Vector q(a[3][0], a[3][1], a[3][2]);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			q[j] += p[i] * a[i][j];
		}
	}
	return q;
}
*/

Matrix operator * (const Matrix &a, const Matrix &b) {
	Matrix ret;
	for (int i = 0; i <= 3; ++i) {
		for (int j = 0; j <= 3; ++j) {
			for (int k = 0; k <= 3; ++k) {
				ret[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return ret;
}

Vector global;

void gloMul(const Matrix &a) {
	Vector tmp(a[3][0], a[3][1], a[3][2]);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			tmp[j] += global[i] * a[i][j];
		}
	}
	global = tmp;
}

Matrix globalM;

void fastMul(Matrix &A, const Matrix &B) {
	globalM.clear();
	for (int i = 0; i <= 3; ++i) {
		for (int j = 0; j <= 3; ++j) {
			for (int k = 0; k <= 3; ++k) {
				globalM[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	globalM[3][3] = 1;
	for (int i = 0; i <= 3; ++i) {
		for (int j = 0; j <= 3; ++j) {
			A[i][j] = globalM[i][j];
		}
	}
}

Matrix Translation(const Vector &p) {
	Matrix ret(1);
	ret[3][0] = p[0];
	ret[3][1] = p[1];
	ret[3][2] = p[2];
	return ret;
}

Matrix Scaling(const double &r) {
	Matrix ret(1);
	ret[0][0] = r;
	ret[1][1] = r;
	ret[2][2] = r;
	return ret;
}

Matrix Scaling(const Vector &p, const double &r) {
	return Translation(-p) * Scaling(r) * Translation(p);
}


Matrix Rotate(const Vector &s, const double &r) {
	double l = s.len(), x = s.a[0] / l, y = s.a[1] / l, z = s.a[2] / l, SinA = sin(r), CosA = cos(r);
	double buf[4][4] = {
	{CosA + (1 - CosA) * x * x, (1 - CosA) * x * y - SinA * z, (1 - CosA) * x * z + SinA * y, 0},
	{(1 - CosA) * y * x + SinA * z, CosA + (1 - CosA) * y * y, (1 - CosA) * y * z - SinA * x, 0},
	{(1 - CosA) * z * x - SinA * y, (1 - CosA) * z * y + SinA * x, CosA + (1 - CosA) * z * z, 0},
	{0, 0, 0, 1}};
	Matrix ret;
	for (int i = 0; i <= 3; ++i) {
		for (int j = 0; j <= 3; ++j) {
			ret[i][j] = buf[i][j];
		}
	}
	return ret;
}

Matrix Rotate(const Vector &p, const Vector &s, const double &r) {
	return Translation(-p) * Rotate(s, -r) * Translation(p);
}

const int N = 300005;

int n, m;

Vector p[N];

inline int getID(int l, int r) {
	return l + r | l != r;
}

const int TN = N << 1;

double len[TN], tag[TN];

void pushdown(int l, int r) {
	int x = getID(l, r), m = l + r >> 1, lc = getID(l, m), rc = getID(m + 1, r);
	tag[lc] = tag[lc] * tag[x];
	len[lc] = len[lc] * tag[x];
	tag[rc] = tag[rc] * tag[x];
	len[rc] = len[rc] * tag[x];
	tag[x] = 1;
}

void update(int l, int r) {
	int x = getID(l, r), m = l + r >> 1, lc = getID(l, m), rc = getID(m + 1, r);
	len[x] = len[lc] + len[rc];
}

void change(int l, int r, int pos, double val) {
	int x = getID(l, r);
	if (l == r) {
		len[x] = val;
		tag[x] = 1;
		return;
	}
	pushdown(l, r);
	int m = l + r >> 1;
	if (pos <= m) {
		change(l, m, pos, val);
	} else {
		change(m + 1, r, pos, val);
	}
	update(l, r);
}

void multi(int l, int r, int a, int b, double mul) {
	if (a <= l && r <= b) {
		int x = getID(l, r);
		tag[x] = tag[x] * mul;
		len[x] = len[x] * mul;
		return;
	}
	pushdown(l, r);
	int m = l + r >> 1;
	if (a <= m) {
		multi(l, m, a, b, mul);
	}
	if (b > m) {
		multi(m + 1, r, a, b, mul);
	}
	update(l, r);
}

double getSum(int l, int r, int a, int b) {
	if (a <= l && r <= b) {
		return len[getID(l, r)];
	}
	pushdown(l, r);
	int m = l + r >> 1;
	double ret = 0;
	if (a <= m) {
		ret += getSum(l, m, a, b);
	}
	if (b > m) {
		ret += getSum(m + 1, r, a, b);
	}
	return ret;
}

Matrix tr[TN];

void pushdown2(int l, int r) {
	int x = getID(l, r), m = l + r >> 1, lc = getID(l, m), rc = getID(m + 1, r);
	if(!tr[x].checkI()){
		fastMul(tr[lc], tr[x]);
		fastMul(tr[rc], tr[x]);
		tr[x].clear(1);
	}
}

void cover(int l, int r, int a, int b, const Matrix &A) {
	if (a <= l && r <= b) {
		int x = getID(l, r);
		fastMul(tr[x], A);
		return;
	}
	pushdown2(l, r);
	int m = l + r >> 1;
	if (a <= m) {
		cover(l, m, a, b, A);
	}
	if (b > m) {
		cover(m + 1, r, a, b, A);
	}
}

void coordinate(int l, int r, int pos) {
	int x = getID(l, r);
	if (l == r) {
		global[0] = tr[x][3][0];
		global[1] = tr[x][3][1];
		global[2] = tr[x][3][2];
		return;
	}
	int m = l + r >> 1;
	if (pos <= m) {
		coordinate(l, m, pos);
	} else {
		coordinate(m + 1, r, pos);
	}
	gloMul(tr[x]);
}

Vector getCoordinate(int l, int r, int pos) {
	coordinate(l, r, pos);
	return global;
}

void perform(int l, int r, const Matrix &A, bool scale = false, double mul = 0) {
	cover(0, n - 1, l, r, A);
	if (l > 0) {
		Vector v0 = getCoordinate(0, n - 1, l - 1),
			   v1 = getCoordinate(0, n - 1, l);
		change(0, n - 2, l - 1, (v0 - v1).len());
	}
	if (r < n - 1) {
		Vector v0 = getCoordinate(0, n - 1, r),
			   v1 = getCoordinate(0, n - 1, r + 1);
		change(0, n - 2, r, (v0 - v1).len());
	}
	if (scale) {
		if (l < r) {
			multi(0, n - 2, l, r - 1, mul);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	{
		for (int i = 0; i <= n * 2; ++i) {
			tr[i].clear(1);
			len[i] = 0;
			tag[i] = 1;
		}
		static int id = 0;
		for (int i = 0; i < n; ++i) {
			perform(i, i, Translation(Vector(i + 1, 0)));
		}
		while (m--) {
			int op, id, d;
			scanf("%d%d%d", &op, &id, &d);
			--id;
			if (op == 1) {
				Vector u, v;
				coordinate(0, n - 1, id);
				u = global;
				if (id) {
					coordinate(0, n - 1, id - 1);
					v = global;
				} else {
					v = Vector(0, 0);
				}
				perform(id, n - 1, Translation((u - v).unit(d)));
			} else if (op == 2) {
				Vector u, v(0, 0, -1);
				if (id) {
					coordinate(0, n - 1, id - 1);
					u = global;
				} else {
					u = Vector(0, 0);
				}
				double rad = d * PI / 180;
				perform(id, n - 1, Rotate(u, v, rad));
			}
			coordinate(0, n - 1, n - 1);
			Vector ans = global;
			printf("%.12f %.12f\n", ans[0], ans[1]);
		}
	}
	return 0;
}