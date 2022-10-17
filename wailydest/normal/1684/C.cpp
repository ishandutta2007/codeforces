#include <cstdio>
#include <algorithm>
#include <utility>

const int N = 200000;
int t, n, m, *a[N], arr[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			a[i] = new int [m];
			for (int j = 0; j < m; ++j) scanf("%d", a[i] + j);
		}
		int px = -1, py = -1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) arr[j] = a[i][j];
			std::sort(arr, arr + m);
			for (int j = 0; j < m; ++j) if (arr[j] != a[i][j]) {
				if (px == -1) px = j;
				else py = j;
			}
		}
		if (px == -1 && py == -1) printf("1 1\n");
		else {
			if (py == -1) py = 0;
			for (int i = 0; i < n; ++i) std::swap(a[i][px], a[i][py]);
			bool ok = 1;
			for (int i = 0; i < n; ++i) for (int j = 1; j < m; ++j) if (a[i][j] < a[i][j - 1]) ok = 0;
			if (ok) printf("%d %d\n", px + 1, py + 1);
			else printf("-1\n");
		}
	}
	return 0;
}