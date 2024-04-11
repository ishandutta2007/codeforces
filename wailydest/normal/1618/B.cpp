#include <cstdio>
#include <cstring>

int t, n;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		char cur[3], prev[3];
		bool ok = 0;
		for (int i = 0; i < n - 2; ++i) {
			scanf("%s", cur);
			if (!i) printf("%c", cur[0]);
			if (i && cur[0] != prev[1]) {
				printf("%c", cur[0]);
				ok = 1;
			}
			printf("%c", cur[1]);
			strcpy(prev, cur);
		}
		if (!ok) printf("a");
		printf("\n");
	}
	return 0;
}