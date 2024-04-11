#include <cstdio>
#include <algorithm>

int t, r, b, d;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		int r, b, d;
		scanf("%d%d%d", &r, &b, &d);
		if ((long long)std::min(r, b) * (1 + d) >= std::max(r, b)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}