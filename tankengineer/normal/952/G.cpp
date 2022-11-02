#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int L = 250;

char buf[L + 1];

void clear() {
	for (int i = 0; i < L; ++i) {
		buf[i] = '.';
	}
}

void add(int delta) {
	if (delta == 1) {
		clear();
		buf[1] = 'X';
		puts(buf);
		clear();
		puts(buf);
	} else if (delta >= 2) {
		int n = 1;
		while ((n + 1) * (n + 1) <= delta) {
			++n;
		}
		int mid = n;
		clear();
		buf[mid] = 'X';
		puts(buf);
		for (int i = 1; i <= n; ++i) {
			buf[mid - i] = buf[mid + i] = 'X';
			puts(buf);
		}
		clear();
		puts(buf);
		int left = delta - n * n;
		if (left) {
			add(left);
		}
	}
}

void print() {
	clear();
	buf[0] = buf[L - 1] = 'X';
	puts(buf);
	buf[L - 1] = '.';
	puts(buf);
	clear();
	puts(buf);
}

void add_print(int delta) {
	add(delta);
	print();
}

void sub(int delta) {
	int f = 0;
	while (delta) {
		clear();
		for (int i = 0; i < 40 && delta; i += 2) {
			buf[i + f] = 'X';
			--delta;
		}
		f ^= 1;
		puts(buf);
	}
	clear();
	puts(buf);
}

void sub_print(int delta) {
	sub(delta);
	print();
}

int main() {
	buf[L] = 0;
	clear();
	puts(buf);
	clear();
	buf[0] = buf[L - 1] = 'X';
	puts(buf);
	clear();
	puts(buf);
	char s[105];
	gets(s);
	int cur = 0, l = strlen(s);
	for (int i = 0; i < l; ++i) {
		int nxt = s[i];
		if (nxt > cur) {
			cur += 256;
		}
		sub_print(cur - nxt);
		cur = nxt;
	}
	return 0;
}