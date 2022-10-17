#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

#define ll long long
#define double long double

const int MAXN = 400400;
const double eps = 1e-9;
inline int sgn (double x, double y = 0) { return (x - y > eps) - (x - y < -eps); }

struct vec {
	double x, y;
	vec (double _x = 0, double _y = 0) { x = _x, y = _y; }
	vec operator + (const vec &tmp) const { return vec(x + tmp.x, y + tmp.y); }
	vec operator - (const vec &tmp) const { return vec(x - tmp.x, y - tmp.y); }
	bool operator == (const vec &tmp) const { return !sgn(x, tmp.x) && !sgn(y, tmp.y); }
	double len () { return x * x + y * y; }
	double angle () { return atan2(y, x); }
} a[MAXN], b[MAXN], tmp[MAXN];

long long cross (vec v1, vec v2) { return ((ll)v1.x) * ((ll)v2.y) - ((ll)v2.x) * ((ll)v1.y); }
bool cmp (vec p1, vec p2) {
	if (cross(p1, p2) == 0) return p1.len() < p2.len();
	return cross(p1, p2) > 0;
}
double angle (vec v1, vec v2) {
	double d1 = v1.angle(), d2 = v2.angle();
	if (d1 < d2) return d2 - d1; else return 2 * acos(-1) + d2 - d1;
	return cross(v1, v2) / v1.len() / v2.len();
}

vec stk[MAXN]; int top;
vec res[MAXN], sav[MAXN]; int ttt = 0;

int nex[MAXN];

void work (int N, bool sss = 0) {
	int i, j;
	top = 0;
	for (i = 2; i <= N; i++) if (tmp[i].y < tmp[1].y || (!sgn(tmp[i].y, tmp[1].y) && tmp[i].x < tmp[1].x)) swap(tmp[i], tmp[1]);
	// printf("gu %.2lf %.2lf\n", tmp[1].x, tmp[i].y);
	for (i = 2; i <= N; i++) tmp[i].x -= tmp[1].x, tmp[i].y -= tmp[1].y; //, printf("! %.2lf %.2lf\n", tmp[i].x, tmp[i].y);
	sort(tmp + 2, tmp + N + 1, cmp);
	stk[++top] = vec(0, 0);
	for (i = 2; i <= N; i++) {
		// printf("! %.2lf %.2lf | %.2lf\n", tmp[i].x, tmp[i].y, cross(stk[top - 1] - stk[top], tmp[i] - stk[top]));
		while (top >= 2 && cross(stk[top - 1] - stk[top], tmp[i] - stk[top]) >= 0) --top;
		stk[++top] = tmp[i];
	}
	for (i = 1; i <= top; i++) stk[i] = stk[i] + tmp[1];
	// for (i = 1; i <= top; i++) printf("%.2lf %.2lf\n", stk[i].x, stk[i].y);
	stk[top + 1] = stk[1]; stk[top + 2] = stk[2];
	for (i = 1; i <= top; i++) res[i] = vec((stk[i + 1] - stk[i]).len(), angle(stk[i] - stk[i + 1], stk[i + 2] - stk[i + 1])); //, printf("%.2lf %.2lf\n", res[i].x, res[i].y);
	if (sss) {
		for (i = 1; i <= top; i++) sav[i + top * 2 + 1] = sav[i + top * 3 + 1] = sav[i] = sav[i + top] = res[i];
		reverse(sav + top * 2 + 2, sav + top * 4 + 2);
		ttt = top;
	}
	// puts("END");
}

int n, m;

int main () {
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);
	n = read(), m = read(); int i, j;
	for (i = 1; i <= n; i++) tmp[i].x = read(), tmp[i].y = read();
	work(n, 1); for (i = 1; i <= m; i++) tmp[i].x = read(), tmp[i].y = read(); work(m);
	if (ttt != top) puts("NO");
	else {
		sav[top * 2 + 1] = vec(1e18, 1e18);
		// for (i = 1; i <= top; i++) printf("%.2Lf %.2Lf\n", res[i].x, res[i].y);
		// puts("");
		// for (i = 1; i <= top * 4 + 1; i++) printf("%.2Lf %.2Lf\n", sav[i].x, sav[i].y);
		nex[1] = 0;
		for (i = 2, j = 0; i <= top; i++) {
			while (j && !(res[j + 1] == res[i])) j = nex[j];
			if (res[j + 1] == res[i]) ++j;
			nex[i] = j;
		}
		for (i = 1, j = 0; i <= top * 4 + 1; i++) {
			while (j && !(res[j + 1] == sav[i])) j = nex[j];
			if (res[j + 1] == sav[i]) ++j;
			if (j == top) { 
				puts("YES");
				return 0;
			}
		}
		puts("NO");
	}
	return 0;
}