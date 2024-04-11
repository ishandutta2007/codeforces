#include <cstdio>

int main() {
	int T;
	scanf("%d\n", &T);
	while(T--) {
		int a, b;
		scanf("%d %d\n", &a, &b);
		int d = (a > b) ? (a-b) : (b-a);
		printf("%d\n", d/5 + (d%5+1)/2);
	}
}