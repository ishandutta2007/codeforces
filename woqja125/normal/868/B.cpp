#include<stdio.h>
int main() {
	int h, m, s, t1, t2;
	scanf("%d%d%d%d%d", &h, &m, &s, &t1, &t2);
	h %= 12; t1 %= 12; t2 %= 12;
	m = m * 60 + s;
	h = h * 3600 + m;
	m *= 12;
	s *= 12 * 60;
	t1 *= 3600;
	t2 *= 3600;

	if (t2 < t1) t2 ^= t1 ^= t2 ^= t1;

	if (t1 <= h && h <= t2 && t1 <= m && m <= t2 && t1 <= s && s <= t2) {
		printf("YES\n");
		return 0;
	}
	
	if ((h <= t1 || h >= t2) && (m <= t1 || m >= t2) && (s <= t1 || s >= t2)) {
		printf("YES\n");
		return 0;
	}

	printf("NO\n");
	return 0;
}