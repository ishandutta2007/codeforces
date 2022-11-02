#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const ull modn = 1000000007ull;
inline ull mod(ull x) { return (x % modn); }
int k, n;
int ball[1009];

ull comb(int m, int x, ull &tot, ull &divv) {
	int i, j;
	if(m - x > x) x = m - x;
	for(i = x + 1; i <= m; i++)
		tot = mod(tot * i);
	for(i = max(m - x, 1); i >= 1; i--)
		divv = mod(divv * i);
}

void mdc(ull a, ull b, ull &s) {
	ull r, old_r, old_s;
	old_r = 1; old_s = 0;
	r = 0; s = 1;
	while(b > 0) {
		// printf("b() ", b);
		ull d = a / b;
		a -= b * d; swap(a, b);
		old_r = mod(old_r - mod(r * d) + modn); swap(r, old_r);
			// printf("s() old_s()\n", s, old_s);

			// printf("count() other()\n\n", mod(old_s * d), mod(s - mod(old_s * d) + modn));
		old_s = mod(old_s - mod(s * d) + modn); swap(s, old_s);
					// printf("s() old_s()\n", s, old_s);

	}
	swap(r, old_r); swap(s, old_s);
	// printf("s() old_s()\n", s, old_s);
}

int main() {
	int i, j;
	scanf("%d", &k);
	for(i = 0; i < k; i++) {
		scanf("%d", &ball[i]);
		n += ball[i];
	}
	ull total = 1;
	ull total_div = 1;
	int nn = n;
	for(i = k - 1; i >= 0; i--) {
		// total *= 1;
		// printf("comb(%d, %d)\n", nn - 1, ball[i] - 1);
		comb(nn - 1, ball[i] - 1, total, total_div);
		// printf("i(%d) ", i);
		// printf("total() div()\n", total, total_div);

		nn -= ball[i];
	}
	// printf("total() div()\n", total, total_div);
	ull inv;
	mdc(modn, total_div, inv);
	total = mod(total * inv);
	printf("%d\n", (int) total);
}