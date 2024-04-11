#include <cstdio>

int t, h, w;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		int h, w;
		scanf("%d%d", &h, &w);
		for (int i = 0; i < w; ++i) {
			if (i == w - 1 || !(i & 1) && i + 1 != w - 1) printf("1");
			else printf("0");
		}
		printf("\n");
		for (int i = 1; i < h - 1; ++i) {
			if (i & 1) printf("0");
			else printf("1");
			for (int j = 1; j < w - 1; ++j) printf("0");
			if (i & 1) printf("0");
			else printf("1");
			printf("\n");
		}
		if (h - 1 & 1) printf("0");
		else printf("1");
		for (int i = 1; i < w - 1; ++i) {
			if (!(i & 1) && i + 1 != w - 1) printf("1");
			else printf("0");
		}
		if (h - 1 & 1) printf("0");
		else printf("1");
		printf("\n");
	}
	return 0;
}