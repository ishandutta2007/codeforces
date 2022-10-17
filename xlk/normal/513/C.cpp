#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int l[5], r[5], n;
double F(vector<int>L, vector<int>R) {
	double E = 0;
	int mx = 0;
	for (int i = 0; i < L.size(); i++) {
		mx = max(mx, R[i]);
	}
	for (int i = 0; i < mx; i++) {
		double p = 1;
		for (int j = 0; j < L.size(); j++) {
			p *= (double)(min(max(i - L[j] + 1, 0), R[j] - L[j] + 1)) / (R[j] - L[j] + 1);
		}
		E += 1 - p;
	}
	return E;
}
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &l[i], &r[i]);
	}
	vector<int>L, R;
	double ans = 0;
	for (int i = 0; i < n; i++) {
		L.push_back(l[i]);
		R.push_back(r[i]);
	}
	ans -= (n - 1) * F(L, R);
	for (int i = 0; i < n; i++) {
		vector<int>L, R;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				L.push_back(l[j]);
				R.push_back(r[j]);				
			}
		}
		ans += F(L, R);
	}

	printf("%.15f\n", ans);
}