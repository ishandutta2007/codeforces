#include <cstdio>

using namespace std;

char w[101];

int main() {
	int n, f = 0;
	scanf ("%d\n", &n);
	gets (w);
	if (n & 1) { f = 1; n--; }
	for (int i = 0; i < n; i++) {
		if (i != 0 && (i & 1) == 0) printf ("-");
		printf ("%c", w[i]);
	}
	if (f) printf ("%c", w[n]);
	printf ("\n");
	return 0;
}