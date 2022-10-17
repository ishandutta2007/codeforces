#include <cstdio>

const int N = 50;
int t;
char s[N + 1];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		int amt = 0;
		for (int i = 0; s[i]; ++i) {
			++amt;
			if (s[i] == 'E') --amt;
		}
		if (amt == 1) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}