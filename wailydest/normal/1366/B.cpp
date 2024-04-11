#include <cstdio>
#include <algorithm>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, x, m;
		scanf("%d%d%d", &n, &x, &m);
		int l = x, r = x;
		int li, ri;
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &li, &ri);
			if (!(li > r || ri < l)) {
				l = min(li, l);
				r = max(ri, r);
			}
		}
		printf("%d\n", r - l + 1);
	}
	return 0;
}