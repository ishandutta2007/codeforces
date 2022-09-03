#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int m, x[100];

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	sort (x, x + n);
	for (int j = 0; j < n; j++) 
		if (x[j] > x[0]) {
			printf ("%d\n", x[j]);
			return 0;
		}
	printf ("NO\n");
	return 0;
}