#ifndef ONLINE_JUDGE
#define debug(...) {fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, __VA_ARGS__);}
#else
#define debug(...) //
#endif
#include <cstdio>
#include <algorithm>
using namespace std;

bool sort_a;

struct St {
	int i;
	int a;
	int pos;
	bool operator < (const St &o) const {
		if(sort_a) return a > o.a;
		return i < o.i;
	}
} s[2007];

int main() {
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		s[i].i = i;
		scanf("%d", &s[i].a);
	}
	sort_a = true;
	sort(s, s + n);
	sort_a = false;
	int j = 1;
	s[0].pos = j;
	for(i = 1; i < n; i++) {
		if(s[i].a != s[i - 1].a) j = i + 1;
		s[i].pos = j;
	}
	sort(s, s + n);
	printf("%d", s[0].pos);
	for(i = 1; i < n; i++)
		printf(" %d", s[i].pos);
	putchar('\n');
	return 0;
}