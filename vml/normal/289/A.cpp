#include <cstdio>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int s = 0;
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		s = (s + r - l + 1) % k;
	}
	printf("%d", (k - s) % k);
	return 0;
}