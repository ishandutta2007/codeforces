#include<cstdio>
#include<algorithm>
using namespace std;

int n, h[105], f[105], ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
  f[0] = 2000;
  for (int i = 1; i <= n; ++i) {
	  for (int j = f[i - 1] - 1999; j <= n; ++j) {
		  if (h[j] == i) {
			  f[i] = j + 2000;
			  break;
			}
		}
		if (!f[i]) break;
		++ans;
	}
	printf("%d\n", ans);
	for (int i = 1; i < ans; ++i) printf("%d ", f[i]);
	if (ans) printf("%d\n", f[ans]);
	return 0;
}