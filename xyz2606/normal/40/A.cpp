#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int x, y;
	scanf("%d%d", &x, &y);
	int dist = x * x + y * y;
	if (x == 0 || y == 0) {
		puts("black");
		return 0;
	}
	
	for (int i = 0; i <= 2000;i++) {
		int d = i * i;
		int dd = (i + 1) * (i + 1);
		
		if (dist == d ) {puts("black"); return 0;}
		if (dist == dd) {puts("black"); return 0;}
		
		int ans;
		if (dist > d && dist < dd) {
			if (x > 0 && y > 0) ans = (i + 1) % 2;
			if (x > 0 && y < 0) ans = i % 2;
			if (x < 0 && y < 0) ans = (i + 1) % 2;
			if (x < 0 && y > 0) ans = i % 2;
			if (ans & 1) puts("black");
			else puts("white");
			return 0;
		}
	}

	return 0;
}