#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <numeric>
#include <memory.h>
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define ui unsigned int
#define ld double

using namespace std;

const int maxn = (int)3e5 + 10;

struct vt {
	ld x, y;

	vt(): x(0), y(0) {

	}

	vt(ld x, ld y): x(x), y(y) {

	}
};

vt operator +(vt a, vt b) {
	a.x += b.x;
	a.y += b.y;

	return a;
}

struct mat {
	ld a[2][2];

	mat() {
		memset(a, 0, sizeof a);
	}

	mat(ld b, ld c, ld d, ld f) {
		a[0][0] = b;
		a[0][1] = c;
		a[1][0] = d;
		a[1][1] = f;
	}
};

mat operator *(mat x, mat y) {
	mat ans;
	memset(ans.a, 0, sizeof ans.a);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ans.a[i][j] += x.a[i][k] * y.a[k][j];
			}
		}
	}

	return ans;
}

vt operator *(mat x, vt a) {
	return vt(x.a[0][0] * a.x + x.a[0][1] * a.y, x.a[1][0] * a.x + x.a[1][1] * a.y);
}

vt tr[4 * maxn];
mat st[4 * maxn];

void build(int it, int l, int r) {
	if (l == r) {
		tr[it] = vt(1, 0);
	} else {
		int m = (l + r) / 2;
		st[it].a[0][0] = 1;
		st[it].a[1][1] = 1;
		st[it].a[0][1] = 0;
		st[it].a[1][0] = 0;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);

		tr[it] = tr[2 * it] + tr[2 * it + 1];
	}
}

void sets(int it, mat x) {
	st[it] = x * st[it];
	tr[it] = x * tr[it];
}

bool operator ==(mat x, mat y) {
	for (int i = 0; i < 2; i++ ) {
		for (int j = 0; j < 2; j++) {
			if (x.a[i][j] != y.a[i][j]) {
				return false;
			}
		}
	}

	return true;
}

bool operator !=(mat x, mat y) {
	return !(x == y);
}

mat e(1, 0, 0, 1);

void push(int it) {
	if (st[it] != e) {
		sets(2 * it, st[it]);
		sets(2 * it + 1, st[it]);

		st[it] = e;
	}
}

ld dst(vt a) {
	return hypot(a.x, a.y);
}

vt operator /(vt a, ld x) {
	a.x /= x;
	a.y /= x;

	return a;
}

vt operator *(vt a, ld x) {
	a.x *= x;
	a.y *= x;

	return a;
}

void change(int it, int l, int r, int lm, int rm, mat x) {
	if (l == lm && r == rm) {
		if (x.a[0][1] != 0) {
			sets(it, x);
		} else {
			ld d = dst(tr[it]);
			tr[it] = tr[it] / d;
			tr[it] = tr[it] * (d + x.a[0][0]);
		}
	} else {
		push(it);
		int m = (l + r) / 2;

		if (rm <= m) {
			change(2 * it, l, m, lm, rm, x);
		} else if (lm > m) {
			change(2 * it + 1, m + 1, r, lm, rm, x);
		} else {
			change(2 * it, l, m, lm, m, x);
			change(2 * it + 1, m + 1, r, m + 1, rm, x);
		}

		tr[it] = tr[2 * it] + tr[2 * it + 1];
	}
}

const ld pi = acos(-1.0);

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	build(1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		int tp, pos;
		ld z;

		scanf("%d %d %lf", &tp, &pos, &z);
		pos--;

		mat x;

		if (tp == 1) {
			x = mat(z, 0, 0, z);
			change(1, 0, n - 1, pos, pos, x);
		} else {
			z /= 180;
			z *= pi;
			x = mat(cos(z), sin(z), -sin(z), cos(z));
			change(1, 0, n - 1, pos, n - 1, x);
		}

		printf("%.5lf %.5lf\n", tr[1].x, tr[1].y);
	}

	return 0;
}