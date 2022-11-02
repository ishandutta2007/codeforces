#include <bits/stdc++.h>

void print(int o, int x, int y) {
	printf("%d %d %d\n", o, x, y);
	fflush(stdout);
}

int main() {
	int n, k; scanf("%d", &n);
	
	int x1 = 1, y1 = 1, x2 = 1, y2 = 2;
	while( true ) {
		scanf("%d", &k);
		if( k == 1 ) {
			print(2, x2, y2), y2 += 2;
			if( y2 > n ) x2++, y2 = (x2 & 1) ? 2 : 1;
			if( x2 > n ) break;
		} else {
			print(1, x1, y1), y1 += 2;
			if( y1 > n ) x1++, y1 = (x1 & 1) ? 1 : 2;
			if( x1 > n ) break;
		}
	}
	
	if( x1 > n ) {
		while( true ) {
			scanf("%d", &k);
			print(k == 2 ? 3 : 2, x2, y2), y2 += 2;
			if( y2 > n ) x2++, y2 = (x2 & 1) ? 2 : 1;
			if( x2 > n ) break;
		}
	} else {
		while( true ) {
			scanf("%d", &k);
			print(k == 1 ? 3 : 1, x1, y1), y1 += 2;
			if( y1 > n ) x1++, y1 = (x1 & 1) ? 1 : 2;
			if( x1 > n ) break;
		}
	}
}