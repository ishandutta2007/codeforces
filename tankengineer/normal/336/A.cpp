#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	int x, y, d;
	scanf("%d%d", &x, &y);
	if (x > 0 && y > 0) {
		d = x + y;
		printf("0 %d %d 0\n", d, d);
	}
	if (x > 0 && y < 0) {
		d = x - y;
		printf("0 %d %d 0\n", -d, d);
	}
	if (x < 0 && y < 0) {
		d = -x - y;
		printf("%d 0 0 %d\n", -d, -d);
	}
	if (x < 0 && y > 0) {
		d = -x + y;
		printf("%d 0 0 %d\n", -d, d);
	}
	return 0;
}