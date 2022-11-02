#include<cstdio>
#include<algorithm>
using namespace std;

int cnt[105], ans, anst;

int main() {
	int n, m, k, d[105], p;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) scanf("%d", &d[i]);
  for (int i = 1; i <= k; ++i) {
	  scanf("%d", &p);
		for (int j = 1; j <= m; ++j) {
		  if (p % d[j] == 0) {
				cnt[j]++;
			}
		}
	}
	ans = 1; anst = 1;
	for (int i = 2; i <= m; ++i) {
	  if (cnt[i] < cnt[anst]) {
		  ans = 1;
		  anst = i;
		} else if (cnt[i] == cnt[anst]) {
		  ++ans;
		}
	} 
  printf("%d\n", ans);
  for (int i = 1; i <= m; ++i) {
	  if (cnt[i] == cnt[anst]) {
		  printf("%d", i);
		  if (--ans) printf(" "); else printf("\n");
		}
	}
	return 0;
}