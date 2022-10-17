#include <cstdio>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		int a[200000];
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		bool p[200000] = {0};
		for (int i = 1; i < n - 1; ++i) if (a[i] > a[i - 1] && a[i] > a[i + 1]) p[i] = true;
		int current = 0, mx, ind = 0;
		for (int i = 1; i < k - 1; ++i) if (p[i]) ++current;
		mx = current;
		for (int i = 1; i + k - 1 < n; ++i) {
			if (p[i]) --current;
			if (p[i + k - 2]) ++current;
			if (current > mx) {
				mx = current;
				ind = i;
			}
		}
		printf("%d %d\n", mx + 1, ind + 1);
	}
	return 0;
}