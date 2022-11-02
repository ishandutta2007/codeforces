#include <bits/stdc++.h>

int main() {
	int T; scanf("%d", &T);
	while( T-- ) {
		int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int d = std::abs(x1 - x2) + std::abs(y1 - y2);
		if( x1 != x2 && y1 != y2 ) d += 2;
		printf("%d\n", d);
	}
}