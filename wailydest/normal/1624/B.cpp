#include <cstdio>
#include <algorithm>

int t, a[3];

bool go(int a, int b) 
{
	if (a == b) return 1;
	if (!a) return 0;
	if (!(b % a) && b / a > 0) return 1;
	return 0;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 3; ++i) scanf("%d", a + i);
		bool ok = 0;
		if (go(a[0], a[1] * 2 - a[2]) || go(a[2], a[1] * 2 - a[0]) || a[0] + a[2] & 1 ^ 1 && go(a[1], a[0] + a[2] >> 1)) ok = 1;
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}