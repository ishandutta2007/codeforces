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
double cx[3], cy[3];
double x[6], y[6];
int p[3];

double vect (double x1, double y1, double x2, double y2) {
	return x1 * y2 - x2 * y1;
}

int cross (double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double *xc, double *yc) {
	double a = x2 - x1;
	double b = x3 - x4;
	double c = x3 - x1;
	double d = y2 - y1;
	double e = y3 - y4;
	double f = y3 - y1;
	double t = (c * e - b * f) / (a * e - b * d);
	*xc = x1 + (x2 - x1) * t;
	*yc = y1 + (y2 - y1) * t;
}

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cx[j] >> cy[j];
			p[j] = j;
		}
		int ok = 0;
		if (fabs (vect (cx[1] - cx[0], cy[1] - cy[0], cx[2] - cx[1], cy[2] - cy[1])) > 1e-8) do {
			double cx1 = (cx[p[0]] + cx[p[1]]) / 2;
			double cy1 = (cy[p[0]] + cy[p[1]]) / 2;
			double cx2 = cx1 + (cy[p[0]] - cy[p[1]]);
			double cy2 = cy1 - (cx[p[0]] - cx[p[1]]);
			double cx3 = (cx[p[1]] + cx[p[2]]) / 2;
			double cy3 = (cy[p[1]] + cy[p[2]]) / 2;
			double cx4 = cx3 + (cy[p[1]] - cy[p[2]]);
			double cy4 = cy3 - (cx[p[1]] - cx[p[2]]);
			cx1 = 2 * cx[p[1]] - cx1;
			cy1 = 2 * cy[p[1]] - cy1;
			cx2 = 2 * cx[p[1]] - cx2;
			cy2 = 2 * cy[p[1]] - cy2;
			double xx, yy;
			cross (cx1, cy1, cx2, cy2, cx3, cy3, cx4, cy4, &xx, &yy);
			x[3] = 2 * cx[p[2]] - xx;
			y[3] = 2 * cy[p[2]] - yy;
			x[2] = xx;
			y[2] = yy;
			x[5] = x[1] = 2 * cx[p[1]] - xx;
			y[5] = y[1] = 2 * cy[p[1]] - yy;
			x[4] = x[0] = 2 * cx[p[0]] - x[1];
			y[4] = y[0] = 2 * cy[p[0]] - y[1];
			ok = 1;
			for (int i = 0; i < 4; i++)
				if (vect (x[i + 1] - x[i], y[i + 1] - y[i], x[i + 2] - x[i + 1], y[i + 2] - y[i + 1]) > -1e-8) {
					ok = 0;
					break;
				}
			if (ok) {
				printf ("YES\n");
				for (int i = 0; i < 4; i++)
					printf ("%.9f %.9f ", x[i], y[i]);
				printf ("\n");
				break;
			}
		} while (next_permutation (p, p + 3));
		if (!ok) printf ("NO\n\n");
	}
	
	return 0;
}