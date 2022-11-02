#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#define debug(args...) //
#endif

#include <cstdio>
#include <cstring>
#include <cstdlib>

inline int abs(int x) {
	return (x < 0)? -x : x;
}

void ok() {
	puts("YES");
	exit(0);
}

void nop() {
	puts("NO");
	exit(0);
}

int main() {
	char str[100005];
	scanf(" %s", str);
	int s = strlen(str);
	int ab1, ab2, ba1, ba2;
	ab1 = ab2 = ba1 = ba2 = -1;
	for(int i = 0; str[i + 1]; i++) {
		if(str[i] == 'A' && str[i + 1] == 'B') {
			if(ab1 >= 0) ab2 = i;
			else ab1 = i;
		} else if(str[i] == 'B' && str[i + 1] == 'A') {
			if(ba1 >= 0) ba2 = i;
			else ba1 = i;
		}
	}
	debug("ab1: %d, ab2: %d, ba1: %d, ba2: %d\n", ab1, ab2, ba1, ba2);
	if(ab2 >= 0 && ba2 >= 0) ok();
	if(ab1 == -1 || ba1 == -1) nop();
	if(abs(ab1 - ba1) > 1) ok();
	if(ba2 >= 0 && abs(ab1 - ba2) > 1) ok();
	if(ab2 >= 0 && abs(ba1 - ab2) > 1) ok();
	nop();
}