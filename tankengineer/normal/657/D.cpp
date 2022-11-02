#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 150005;

int n;

int p[N], tt[N], ord[N], ordp[N];

double t[N];

double T;

double c;

double gth[N], gtt[N];

bool byP(const int &i, const int &j) {
	return p[i] < p[j];
}

int sign(double x, double EPS = 1e-10) {
	return x < -EPS ? -1 : x > EPS;
}

bool Greedy(const int &i, const int &j) {
	double ifirst = 0, jfirst = 0;
	ifirst = p[i] * t[j];
	jfirst = p[j] * t[i];
	return ifirst > jfirst;
}

bool check(double c) {
	double cur = 0;
	for (int ii = 0; ii < n; ++ii) {
		int i = ord[ii];
		int jj = ii;
		double last = cur;
		while (jj < n && sign(p[i] * t[ord[jj]] - p[ord[jj]] * t[i]) == 0) {
			cur += t[ord[jj]];
			++jj;
		}
		for (int k = ii; k < jj; ++k) {
			gth[ord[k]] = p[ord[k]] * (1 - c * (last + t[ord[k]]));
			gtt[ord[k]] = p[ord[k]] * (1 - c * cur);
		}
		ii = jj - 1;
	}
	double preMax = 0;
	for (int ii = 0; ii < n; ++ii) {
		int jj = ii;
		double curMax = 0, curMin = 1e100;
		while (jj < n && p[ordp[jj]] == p[ordp[ii]]) {
			curMax = max(curMax, gth[ordp[jj]]);
			curMin = min(curMin, gtt[ordp[jj]]);
			++jj;
		}
		if (curMin < preMax) {
			return false;
		}
		preMax = max(preMax, curMax);
		ii = jj - 1;
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", p + i);
		ordp[i] = i;
	}
	sort(ordp, ordp + n, byP);
	for (int i = 0; i < n; ++i) {
		scanf("%d", tt + i);
		T += tt[i];
	}
	for (int i = 0; i < n; ++i) {
		t[i] = tt[i] / T;
	}
	for (int i = 0; i < n; ++i) {
		ord[i] = i;
	}
	c = 0.5;
	sort(ord, ord + n, Greedy);
	double l = 0, r = 1;
	for (int i = 0; i < 100; ++i) {
		double m = (l + r) / 2;
		if (check(m)) {
			l = m;
		} else {
			r = m;
		}
	}
	printf("%.12f\n", (l + r) / 2);
	return 0;
}