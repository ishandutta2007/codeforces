#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 300005;

int a, b;

char s[N];

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d%s", &a, &b, s);
		int l = strlen(s);
		int ge2b = 0, a2bm1 = 0, lta = 0, pl = 0;
		for (int i = 0; i < l; ++i) {
			if (s[i] == '.') {
				int j = i;
				while (s[j] == '.') {
					++j;
				}
				int g = j - i;
				i = j;
				if (g < b) {
					continue;
				} else if (g >= 2 * b) {
					++ge2b;
					pl = g;
				} else if (g >= a) {
					++a2bm1;
				} else {
					++lta;
				}
			}
		}
		bool win = true;
		if (lta > 0) {
			win = false;
		} else if (ge2b > 1) {
			win = false;
		} else if (ge2b == 0) {
			win = a2bm1 % 2 == 1;
		} else {
			if (pl > a + 2 * (2 * b - 1)) {
				win = false;
			} else if (a2bm1 % 2 == 0) {
				win = (a <= pl && pl <= a + 2 * (b - 1)) || (3 * a <= pl);
			} else {
				win = 2 * a <= pl && pl <= a + 3 * b - 2;
			}
		}
		if (win) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}