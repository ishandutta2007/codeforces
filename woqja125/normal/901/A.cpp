#include<cstdio>
using namespace std;
int a[100001];
int main() {
	int h;
	scanf("%d", &h);
	for (int i = 0; i <= h; i++)scanf("%d", a + i);
	int i;
	for (i = 1; i <= h; i++)
		if (a[i] != 1 && a[i-1] != 1) break;
	if (i == h+1) {
		printf("perfect\n");
		return 0;
	}
	printf("ambiguous\n");
	int p = 1;
	printf("0 ");
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= a[i]; j++) printf("%d ", p);
		p += a[i-1];
	}
	printf("\n0 ");
	int pl = 1, pr = 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= a[i]; j++) printf("%d ", j<=1?pl:pr);
		pl += a[i - 1];
		pr += a[i];
	}
	return 0;
}