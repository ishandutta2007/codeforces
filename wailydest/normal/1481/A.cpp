#include <cstdio>

const int N = 100000;
int t, x, y;
char s[N + 1];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%s", &x, &y, s);
		for (int i = 0; s[i]; ++i) {
			if (s[i] == 'R' && x > 0) --x;
			if (s[i] == 'L' && x < 0) ++x;
			if (s[i] == 'U' && y > 0) --y;
			if (s[i] == 'D' && y < 0) ++y;
		}
		if (x || y) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}