#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
 
using namespace std;
 
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
 
#define equal equalll
#define less lesss

const int N = -1;
const int C = -1;

int n, k;

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	vector<int> a(n + 1);
	vector<long double> s(n + 1), p(n + 1), t(n + 1), f(n + 1), ff(n + 1), st(n + 1), aa(n + 1), bb(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
		p[i] = p[i - 1] + s[i] * 1.0 / a[i];
		t[i] = t[i - 1] + 1.0 / a[i];
	}
	for (int i = 0; i <= n; i++) f[i] = -1;
	f[0] = 0;
	for (int j = 0; j < k; j++) {
		int cur = 0;
		int cst = 0;
		for (int i = 0; i <= n; i++) {
			if (i <= j) {
				ff[i] = -1;
			} else {
				while ((cur + 1 < cst) && (st[cur + 1] <= t[i])) ++cur;
				ff[i] = aa[cur] * t[i] + bb[cur] + p[i];
			}
			if (f[i] != -1) {
				long double ca = -s[i];
				long double cb = f[i] - p[i] + t[i] * s[i];
				while (cst > 0) {
					long double x = (cb - bb[cst - 1]) / (aa[cst - 1] - ca);
					if (x >= st[cst - 1]) {
						st[cst] = x; aa[cst] = ca; bb[cst] = cb;
						++cst;
						break;
					} else {
						--cst;
					}
				}
				if (cst == 0) {
					st[cst] = 0; aa[cst] = ca; bb[cst] = cb;
					++cst;
				}
			}
		}
		// for (int i = 0; i <= n; i++) cerr << i << " " << (double) ff[i] << endl;
		for (int i = 0; i <= n; i++) f[i] = ff[i];
	}
	printf("%.10lf\n", (double)f[n]);
	return 0;
}