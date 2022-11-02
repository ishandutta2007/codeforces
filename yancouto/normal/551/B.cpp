#ifndef ONLINE_JUDGE
#define debug(...) {fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, __VA_ARGS__);}
#else
#define debug(...) //
#endif
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[30], b[30], c[30];

void make_s(char *str, int v[]) {
	while(*str) {
		v[(*str) - 'a']++;
		str++;
	}
}

int many(int str[], int a[], int t, int b[]) {
	int m = 100009;
	for(int i = 0; i < 26; i++)
		if(a[i] > 0)
			m = min(m, (str[i] - t * b[i]) / a[i]);
	return m;
}

int main() {
	char str[100006], bb[100006], cc[100006];
	scanf(" %s", str);
	make_s(str, a);
	scanf(" %s", bb);
	make_s(bb, b);
	scanf(" %s", cc);
	make_s(cc, c);
	debug("heyo\n");

	int ma = many(a, b, 0, b);
	int best_i = ma;
	int best = ma + many(a, c, ma, b);
	for(int i = ma - 1; i >= 0; i--) {
		int n = i + many(a, c, i, b);
		if(n > best) { best = n; best_i = i; }
	}
	for(int i = 0; i < best_i; i++)
		printf("%s", bb);
	int best_i2 = many(a, c, best_i, b);
	for(int i = 0; i < best_i2; i++)
		printf("%s", cc);
	for(int i = 0; i < 26; i++) {
		int v = a[i] - best_i * b[i] - best_i2 * c[i];
		while(v--) putchar('a' + i);
	}
	putchar('\n');
	return 0;
}