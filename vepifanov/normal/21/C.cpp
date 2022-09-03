#include <cstdio>

using namespace std;

int n;
int m;
int x[100000];

int main() {
	scanf ("%d", &n);
	int s = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x[i]);
		s += x[i];
	}
	if (s % 3 != 0) printf ("0\n"); else {
		int S = s / 3;
		int r = s, y = 0;
		for (int i = 0; i + 1 < n; i++) {
			r -= x[i];
			if (r == S) y++;
		}
		long long ans = 0;
		int l = 0;
		r = s;
		for (int i = 0; i + 1 < n; i++) {
			l += x[i];
			r -= x[i];
			if (r == S) y--;
			if (l == S) ans += y;
		}
		printf ("%I64d\n", ans);
	}
	return 0;
}