#include <cstdio>

using namespace std;

int c[2], l[2];

int main() {
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf ("%d", &a);
		c[a & 1]++;
		l[a & 1] = i + 1;	
	}
	if (c[0] == 1) printf ("%d\n", l[0]); else printf ("%d\n", l[1]);
	return 0;
}