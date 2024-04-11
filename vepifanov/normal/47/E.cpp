#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double g = 9.8;

double ang[200000], x[200000], y[200000];
int p[200000], q[200000], n, v, m;
pair<double, double> res[200000];

bool l1 (int i, int j) {
	return ang[i] < ang[j];
}

bool l2 (int i, int j) {
	return x[i] < x[j];// || fabs (x[i] - x[j]) < 1e-6 && y[i] < y[j] - 1e-6;
}

int main () {
	scanf ("%d%d", &n, &v);
	for (int i = 0; i < n; i++) {
		scanf ("%lf", &ang[i]);
		p[i] = i;
	}
	scanf ("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf ("%lf%lf", &x[i], &y[i]);
		q[i] = i;
	}
	sort (p, p + n, l1);
	sort (q, q + m, l2);
	int j = 0;
	for (int i = 0; i < n; i++) {
		int I = p[i], ok = 0;
		double vx = v * cos (ang[I]);
		double vy = v * sin (ang[I]);
		while (j < m) {
			int J = q[j];
			double t = x[J] / vx;
			double z = vy * t - g * t * t / 2;
			if (z <= y[J]) {
				res[I] = make_pair (x[J], z);
				if (z >= 0) ok = 1;
				break;
			} else j++;
		}
		if (!ok) {
			double t = 2 * vy / g;
			double z = vx * t;
			res[I] = make_pair (z, 0.0);
		}
	}
	for (int i = 0; i < n; i++) printf ("%.10f %.10f\n", res[i].first, res[i].second);
}