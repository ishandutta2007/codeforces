#include <stdio.h>
#include <iostream>
using namespace std;
int a, b, c, d;
int main() {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (a > b) {
		printf("First\n");
	} else {
		printf("Second\n");
	}
	return 0;
}