#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, f[N], b[N], key[N << 2], top, cnt[N << 2], ans, cnts;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
	  scanf("%d %d", &f[i], &b[i]);
	  key[++top] = f[i]; if (f[i] != b[i]) key[++top] = b[i];
	}
	sort(key + 1, key + top + 1);
	for (int i = 1; i <= top; ++i) {
	  if (key[i] != key[i - 1]) cnt[i] = 1; else cnt[i] = cnt[i - 1] + 1;
	}
	cnt[top + 1] = 1;
	ans = n;
	for (int i = 1; i <= top; ++i) {
	  if (cnt[i + 1] == 1 && cnt[i] * 2 >= n) {
			cnts = 0;
		  for (int j = 1; j <= n; ++j) {
			  if (f[j] == key[i]) ++cnts;
			}
			ans = min(ans, max(0, (n / 2 + n % 2) - cnts));
		}
	}
	if (ans == n) ans = -1;
	printf("%d\n", ans);
	return 0;
}