#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  	int a[3];
	for (int i = 0; i < 3; i++) scanf("%d", &a[i]);
	sort(a, a + 3);
	printf("%d\n", a[1] - a[0] + a[2] - a[1]);
}