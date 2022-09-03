#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;
int mask[500][500][17];
int x[500], y[500], X[500], Y[500];
double xx[500], yy[500], XX[500], YY[500];

double vect (double x1, double y1, double x2, double y2) {
	return x1 * y2 - x2 * y1;
}

int main() {
	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf ("%d%d", &x[i], &y[i]);
	for (int i = 0; i < m; i++) scanf ("%d%d", &X[i], &Y[i]);
	double *cx, *cy, *CX, *CY;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) { xx[j] = x[j] - x[i], yy[j] = y[j] - y[i]; }
		for (int j = 0; j < m; j++) { XX[j] = X[j] - x[i]; YY[j] = Y[j] - y[i]; }
		cx = xx + i;
		cy = yy + i;
		for (int j = i + 1; j < n; j++) {
			cx++; cy++;
			CX = XX;
			CY = YY;
			int *ap = mask[i][j], *ar = mask[j][i];
			int b = 0;
			for (int k = 0; k < m; k++, CX++, CY++) {
				if ((*cx) * (*CY) - (*cy) * (*CX) > 0)//A * X[k] + B * Y[k] + C > 0)
					(*ap) |= (1 << b);
				else
					(*ar) |= (1 << b);
				b++;
				if (b == 30) { ap++; ar++; b = 0; }
			}
		}       
	}
	int ans = 0;	
	double *jx, *jy, *kx, *ky;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) { xx[j] = x[j] - x[i]; yy[j] = y[j] - y[i]; }
		jx = xx + i;
		jy = yy + i;
		for (int j = i + 1; j < n; j++) {
			jx++; jy++;
			kx = jx;
			ky = jy;
			for (int k = j + 1; k < n; k++) {
				kx++; ky++;
				if ((*jx) * (*ky) - (*jy) * (*kx) > 0) {//x[k] * A + y[k] * B + C > 0) {
					ans++;
					for (int l = 0; l < 17; l++)
						if (mask[i][j][l] & mask[j][k][l] & mask[k][i][l]) { ans--; break; }
				} else {
					ans++;
					for (int l = 0; l < 17; l++)
						if (mask[i][k][l] & mask[k][j][l] & mask[j][i][l]) { ans--; break; }
				}
			}
		}
	}
	printf ("%d\n", ans);
	return 0;
}