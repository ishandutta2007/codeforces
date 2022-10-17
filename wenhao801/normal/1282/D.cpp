#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

char a[303] = {};

int guess (int len) {
	char b[303] = {};
	for (int i = 0; i < len; i++) b[i] = a[i];
	printf("%s\n", b);
	fflush(stdout);
	int ret = read(); if (!ret) exit(0); return ret;
}

int len, numa, numb;

int main () {
	int i, j;
	for (i = 0; i < 300; i++) a[i] = 'a'; int r1 = guess(300);
	for (i = 0; i < 300; i++) a[i] = 'b'; int r2 = guess(300);
	len = 600 - r1 - r2, numa = r2 - (300 - len), numb = r1 - (300 - len); r2 = numa;
	for (i = 0; i < len - 1; i++) {
		a[i] = 'a';
		if (guess(len) > r2) a[i] = 'b';
		else r2--;
	}
	if (r2) a[len - 1] = 'a'; guess(len);
	return 0;
}