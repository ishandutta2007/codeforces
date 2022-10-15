#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

#define RE register
#define rep(i, l, r) for (RE int i = l; i <= r; i++)
#define rep2(i, l, r) for (RE int i = l; i >= r; i--)

char getch() {
	for (;;) {
		char ch = getchar();
		if (ch != ' ' && ch != '\n' && ch != '\r') return ch;
	}
}

char a[2];
char b[5][2];
int main() {
	a[0] = getch(), a[1] = getch();
	for (int i = 0; i < 5; i++) {
		b[i][0] = getch(), b[i][1] = getch();
		if (b[i][0] == a[0]) return printf("YES\n") & 0;
		if (b[i][1] == a[1]) return printf("YES\n") & 0;
	}
	printf("NO\n");
	return 0;
}