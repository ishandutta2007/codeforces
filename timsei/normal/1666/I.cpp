#include<bits/stdc++.h>
using namespace std;
inline int Ask(int x, int y) {
	printf("SCAN %d %d\n", x, y);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}
inline int Dig(int x, int y) {
	printf("DIG %d %d\n", x, y);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}
int T, n, m;
int main() {
	for(scanf("%d", &T); T --; ) {
		scanf("%d%d", &n, &m); // (r1 < r2, c1 < c2);
		int res1 = Ask(1, 1); // r1 - 1 + c1 - 1 + r2 - 1 + c2 - 1;
		res1 += 1 + 1 + 1 + 1;
		int res2 = Ask(1, m); // r1 - 1 + m - c1 + r2 - 1 + m - c2;
		res2 += 1 - m + 1 - m;
		assert((res1 + res2) % 2 == 0);
		int rpr = (res1 + res2) >> 1, cpc = (res1 - res2) >> 1;
		
		int rmid = rpr >> 1;
		int res3 = Ask(rmid, 1); // rmid - r1 + c1 - 1 + r2 - rmid + c2 - 1;
		int rmr = res3 - cpc + 2; // r2 - r1;
		assert((rpr - rmr) % 2 == 0);
		int r1 = (rpr - rmr) >> 1, r2 = (rpr + rmr) >> 1;

		int cmid = cpc >> 1;
		int res4 = Ask(1, cmid); // r1 - 1 + cmid - c1 + r2 - 1 + c2 - cmid;
		int cmc = res4 - rpr + 2;
		assert((cpc + cmc) % 2 == 0);
		int c1 = (cpc - cmc) >> 1, c2 = (cpc + cmc) >> 1;

		if(Dig(r1, c1))
			Dig(r2, c2);
		else
			Dig(r1, c2), Dig(r2, c1);
	}
}