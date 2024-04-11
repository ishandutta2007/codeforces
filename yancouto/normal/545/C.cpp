#include <cstdio>

int main() {
	int n;
	int x, h;
	int last_2 = 0;
	int last_point, max = 1;
	scanf("%d", &n);
	scanf("%d %d", &last_point, &h);
	for(int i = 1; i < n; i++) {
		scanf("%d %d", &x, &h);
		if(last_2 > last_point && x > last_2) { max++; last_point = last_2; }
		if(x - h > last_point) { // go left
			last_2 = last_point = x;
			max++;
		} else { // try to go right
			last_point = x;
			last_2 = x + h;
		}
	}
	if(last_2 > last_point) max++;
	printf("%d\n", max);
}