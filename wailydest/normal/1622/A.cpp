#include <cstdio>
#include <algorithm>

int t, a[3];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 3; ++i) scanf("%d", a + i);
		bool ok = 0;
		for (int i = 0; i < 3; ++i) {
			if (a[1] == a[2] && a[0] & 1 ^ 1 || a[0] == a[1] + a[2]) ok = 1;
			std::rotate(a, a + 1, a + 3);
		}
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}