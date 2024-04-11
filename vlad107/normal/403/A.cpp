#include <stdio.h>

using namespace std;

int t, n, p;

int main() {
    scanf("%d", &t);
    for (int ii = 0; ii < t; ii++) {
	scanf("%d%d", &n, &p);
	int e = 2 * n + p;
	for (int d = 1; d < n; d++) 
	    for (int i = 1; i + d <= n; i++) {
		if (e == 0) 
		    break;
		printf("%d %d\n", i, i + d);
		--e;
	    }
    }
}