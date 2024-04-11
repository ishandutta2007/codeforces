#include <cstdio>

int t, a[7];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 7; ++i) scanf("%d", a + i);
		printf("%d %d %d\n", a[0], a[1], a[6] - a[0] - a[1]);
	}
}