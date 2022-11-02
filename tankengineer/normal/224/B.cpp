#include<cstdio>
#include<algorithm>
using namespace std;

int n, k, a[100005], cnts[100005], cnt, l;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	  if (!cnts[a[i]]) ++cnt;
	  ++cnts[a[i]];
	  if (cnt == k) {
		  l = 1;
		  while (cnt == k) {
			  --cnts[a[l]];
			  if (!cnts[a[l]]) --cnt;
			  ++l;
			}
			printf("%d %d\n", l - 1, i);
		  return 0;
		}
	}
	printf("-1 -1\n");
	return 0;
}