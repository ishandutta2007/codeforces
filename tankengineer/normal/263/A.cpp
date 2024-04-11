#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int tx, ty, t1;
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= 5; ++j) {
			scanf("%d", &t1);
			if (t1) {
				tx = i;
				ty = j;
			}
		}
	}
	printf("%d\n", max(3 - tx, tx - 3) + max(3 - ty, ty - 3));
	return 0;
}