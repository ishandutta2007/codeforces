#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 6005, TN = N << 2;
const double eps = 1e-9;
int n, x[N];
double q, da, db, ans[N], l[TN], r[TN], a[TN], b[TN];

pair<double, double> getmin(int i) {
	pair<double, double> ret;
	if (a[i] < eps) {
		ret.second = 0;
	} else {
		ret.second = b[i] / a[i];
		if (ret.second > r[i]) {
			ret.second = r[i];
		} else if (ret.second < l[i]) {
			ret.second = l[i];
		}
	}
	ret.first = a[i] * ret.second - b[i];
	return ret;
}

vector<int> dev;

double getroot() {
	pair<double, double> tmp1 = getmin(dev[0]);
	for (int j = 0; j < (int)dev.size(); ++j) {
		pair<double, double> tmp2 = getmin(dev[j]);
		tmp1 = fabs(tmp2.first) < fabs(tmp1.first) ? tmp2 : tmp1;
	}
	return tmp1.second;
}

int main() {
	scanf("%d%lf%lf%lf", &n, &q, &da, &db);
	for (int i = 0; i < n; ++i) {
		scanf("%d", x + i);
	}
	int tot = 0;
	dev.push_back(0);
	l[0] = 1; r[0] = q; a[0] = 1; b[0] = x[0];
	for (int i = 1; i < n; ++i) {
		vector<int> left, right;
		double cut = getroot();
		ans[i - 1] = cut;
		for (int j = 0; j < (int)dev.size(); ++j) {
			int u = dev[j];
			if (r[u] - eps < cut) {
				left.push_back(u);
			} else if (l[u] + eps > cut) {
				right.push_back(u);
			} else {
				++tot;
				l[tot] = cut; r[tot] = r[u]; a[tot] = a[u]; b[tot] = b[u];
				r[u] = cut;
				left.push_back(u);
				right.push_back(tot);
			}
		}
		dev.clear();
		for (int j = 0; j < (int)left.size(); ++j) {
			int u = left[j];
			l[u] += da;
			r[u] = min(r[u] + da, q);
			b[u] += a[u] * da;
			if (l[u] - eps < r[u]) {
				a[u] += 1;
				b[u] += x[i];
				dev.push_back(u);
			}
		}
		++tot;
		l[tot] = cut + da; r[tot] = min(cut + db, q); a[tot] = 1; b[tot] = x[i];
		if (l[tot] - eps < r[tot]) {
			dev.push_back(tot);
		}
		for (int j = 0; j < (int)right.size(); ++j) {
			int u = right[j];
			l[u] += db;
			r[u] = min(r[u] + db, q);
			b[u] += a[u] * db;
			if (l[u] - eps < r[u]) {
				a[u] += 1;
				b[u] += x[i];
				dev.push_back(u);
			}
		}
	}
	ans[n - 1] = getroot();
	for (int i = n - 2; i >= 0; --i) {
		double t = ans[i + 1];
		if (t > ans[i] + db) {
			ans[i] = t - db;
		} else if (t < ans[i] + da) {
			ans[i] = t - da;
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%.12f%c", ans[i], i == n - 1 ? '\n' : ' ');
	}
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += (x[i] - ans[i]) * (x[i] - ans[i]);
	}
	printf("%.12f\n", sum);
	return 0;
}