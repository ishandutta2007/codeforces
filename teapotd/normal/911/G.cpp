#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,tree-vectorize,no-inline-functions")
#pragma GCC target("popcnt,mmx,sse,sse2,sse3,sse4.1,sse4.2,avx,tune=native")

#include <iostream>
using namespace std;

constexpr int MAX_N = 1<<18;
constexpr int BUF_SIZE = 16<<20;

char input[BUF_SIZE], output[BUF_SIZE];
int nIn, nOut;
char elems[MAX_N];

inline __attribute__((always_inline)) int getUint() {
	int n = 0, chr = input[nIn++];
	while (chr == '\n' || chr == ' ') chr = input[nIn++];

	do {
		n = n*10 + chr - '0';
		chr = input[nIn++];
	} while (chr != '\n' && chr != ' ');
	return n;
}

inline __attribute__((always_inline)) void putUint(int n) {
	char str[10];
	int i = 0;

	while (n > 0) {
		str[i++] = char((n % 10) + '0');
		n /= 10;
	}

	while (--i >= 0) output[nOut++] = str[i];
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	fread(input, 1, BUF_SIZE, stdin);

	int n, q, l, r;
	char x, y;

	n = getUint();
	for (int i = 0; i < n; i++) elems[i] = char(getUint());
	q = getUint();

	while (q--) {
		l = getUint()-1;
		r = getUint();
		x = char(getUint());
		y = char(getUint());

		while ((l & 0xF) && l < r) {
			if (elems[l] == x) elems[l] = y;
			l++;
		}

		for (; l < r; l++) if (elems[l] == x) elems[l] = y;
	}

	for (int i = 0; i < n; i++) {
		putUint(elems[i]);
		output[nOut++] = ' ';
	}
	output[nOut++] = '\n';

    fwrite(output, 1, nOut, stdout);
    fflush(stdout);
	return 0;
}