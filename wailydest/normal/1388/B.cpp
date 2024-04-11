#include <cstdio>

const int N = 200000;
int t;
char s[N + 1];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int l = n * 3;
		int p = (n * 3) / 4;
		for (int i = 0; i < p; ++i) printf("9");
		for (int i = p; i < n; ++i) printf("8");
		printf("\n");
	}
	return 0;
}