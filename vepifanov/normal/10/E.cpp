#include <cstdio>

using namespace std;

int n, m;
int x[401];

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	int ans = -1;
	for (int i = 1; i < n; i++)
		for (int j = i; j < n; j++) {
			int w = x[i - 1] - 1, s = 1, S = 0, W;
			for (int k = 0; k <= j; k++) { s += w / x[k]; w %= x[k]; }
			W = w = x[i - 1] + x[j] - 1 - w;
			for (int k = 0; k < n; k++) { S += w / x[k]; w %= x[k]; }
			if (S > s && (ans == -1 || ans > W)) ans = W;
		}
	printf ("%d\n", ans);
	return 0;
}