#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000020];
int gao(int x, int p) {
	int re = 0;
	for (int i:v[p]) {
		re += x / i;
	}
	return re;
}
int main() {
	for (int i = 1; i < 1000010; i++) {
		v[i].push_back(1);
	}
	for (int i = 2; i < 1000010; i++) {
		if (v[i].size() > 1) {
			continue;
		}
		for (int j = i; j < 1000010; j += i) {
			int l = v[j].size();
			for (int k = 0; k < l; k++) {
				v[j].push_back(-v[j][k] * i);
			}
		}
	}
	int t, x, p, k;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d%d%d", &x, &p, &k);
		k += gao(x, p);
		int L = 0, R = 1e9;
		while (L < R - 1) {
			int M = (L + R) / 2;
			if (gao(M, p) < k) {
				L = M;
			} else {
				R = M;
			}
		}
		printf("%d\n", R);
	}
}