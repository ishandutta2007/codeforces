#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
const int maxn = 200010;
using namespace std;
int x[maxn], pre, n, ans;
char d[maxn];
int main() {
	scanf("%d%s", &n, d + 1);
	for (int i = 1; i <= n; ++i)
		scanf("%d", x + i);
	pre = ans = -1;
	for (int i = 1; i <= n; ++i)
		if (d[i] == 'L') {
			if (pre != -1) {
				if (ans == -1 || (x[i] - x[pre] < ans))
					ans = x[i] - x[pre];
			}
		}
		else pre = i;
	if (ans == -1) printf("-1\n");
	else printf("%d\n", ans / 2);
}