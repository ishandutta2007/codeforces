#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, n, a[N];
long long s[N], mn[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		bool neg = false;
		s[0] = a[0];
		int fneg = n;
		for (int i = 1; i < n; ++i) {
			s[i] = a[i] - s[i - 1];
			if (s[i] < 0 && !neg) {
				neg = true;
				fneg = i;
			}
		}
		if (!neg && !s[n - 1]) printf("YES\n");
		else {
			bool ok = false;
			for (int i = n - 1; i >= 0; --i) {
				if (i + 2 < n) mn[i] = std::min(mn[i + 2], s[i]);
				else mn[i] = s[i];
			}
			for (int i = 1; i < n && i <= fneg + 1; ++i) {
				bool z = false;
				if ((n - i) & 1) {
					if (!(s[n - 1] + (long long)2 * (a[i - 1] - a[i]))) z = true;
				}
				else {
					if (!(s[n - 1] + (long long)2 * (a[i] - a[i - 1]))) z = true;
				}
				if (z && s[i - 1] - a[i - 1] + a[i] >= 0 && (i == n - 1 || mn[i + 1] + (long long)2 * (a[i] - a[i - 1]) >= 0) && mn[i] + (long long)2 * (a[i - 1] - a[i]) >= 0) {
					ok = true;
				}
			}
			if (ok) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}