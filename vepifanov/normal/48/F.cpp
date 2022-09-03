#include <cstdio>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <iostream>

using namespace std;

#define re return

typedef long long ll;

int n, m, w;
long long a0, nc, c0;
double a1;
int p[500000], c[500000], a[500000], v[500000];
pair<double, int> all[500000];
double A[500000];

int go (int l, int r, int w) {
	int m = p[(l + r) / 2];
	int k = l;
	for (int i = l; i <= r; i++)
		if ((ll)c[p[i]] * v[m] < (ll)c[m] * v[p[i]] || (ll)c[p[i]] * v[m] == (ll)c[m] * v[p[i]] && (rand () & 1)) {
			swap (p[i], p[k]);
			k++;
		}
	int s = 0;
	for (int i = l; i < k && s < w; i++) s += v[p[i]];
	if (s >= w) {
		if (l == r) {
			a0 += ((ll)w * c[p[l]]) / v[p[l]];
			a1 += (((ll)w * c[p[l]]) % v[p[l]] + 0.0) / v[p[l]];
//			cout << a0 << " " << a1 << endl;
		} else go (l, k - 1, w);
	} else {
		for (int i = l; i < k; i++) a0 += c[p[i]];
//		cout << a0 << endl;
		go (k, r, w - s);
	}
	re 0;
}

int main () {
        scanf ("%d%d%d", &n, &m, &w);
        for (int i = 0; i < m; i++) scanf ("%d", &v[i]);
        for (int i = 0; i < m; i++) scanf ("%d", &c[i]);
        for (int i = 0; i < m; i++) {
                scanf ("%d", &a[i]);
                A[i] = (a[i] + 0.0) / v[i];
        }
        for (int i = 0; i < m; i++) p[i] = i;
        a0 = a1 = 0;
        for (int i = 0; i < n; i++) {
                int ww = w;
        	go (0, m - 1, ww);
                for (int j = 0; j < m; j++) c[j] -= a[j];
        }
        a0 += (long long)a1;
        a1 -= (long long)a1;
        char s[100];
        sprintf (s, "%.15f", a1);
        cout << a0 << s + 1 << endl;
}