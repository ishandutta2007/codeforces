#include <cstdio>
#include <algorithm>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int v;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &v);
			v = abs(v);
			printf("%d ", (i & 1) ? -v : v);
		}
		printf("\n");
	}
	return 0;
}