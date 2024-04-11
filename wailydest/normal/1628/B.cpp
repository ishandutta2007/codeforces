#include <cstdio>
#include <algorithm>

const int X = 200000;
int t, n, a[X];
bool was[X];
char s[4];

int to(const char *s) 
{
	if (s[1]) {
		if (s[2]) return (s[0] - 'a') * 26 * 26 + (s[1] - 'a') * 26 + (s[2] - 'a');
		return 100000 + (s[0] - 'a') * 26 + s[1] - 'a';
	}
	return 0;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		bool ok = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			a[i] = to(s);
			if (s[1]) {
				if (s[2]) {
					if (s[0] == s[2]) ok = 1;
					std::reverse(s, s + 3);
					if (was[to(s)]) ok = 1;
					s[2] = 0;
					if (was[to(s)]) ok = 1;
				} else {
					if (s[0] == s[1]) ok = 1;
					std::reverse(s, s + 2);
					if (was[to(s)]) ok = 1;
					for (int i = 0; i < 26; ++i) {
						s[2] = 'a' + i;
						if (was[to(s)]) ok = 1;
					}
				}
			} else ok = 1;
			was[a[i]] = 1;
		}
		for (int i = 0; i < n; ++i) was[a[i]] = 0;
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
}