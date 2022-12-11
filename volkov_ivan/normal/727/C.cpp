#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int sums[n - 1];
	for (int i = 2; i <= n; i ++) {
		printf("? 1 %d\n", i);
		fflush(stdout);
		cin >> sums[i - 2];
	}
	int x;
	printf("? 2 3\n");
	fflush(stdout);
	cin >> x;
	int fst = (sums[0] - x + sums[1]) / 2;
	printf("! %d", fst);
	for (int i = 0; i < n - 1; i ++) {
		printf(" %d", sums[i] - fst);
	}
	printf("\n");
	fflush(stdout);
	return 0;
}