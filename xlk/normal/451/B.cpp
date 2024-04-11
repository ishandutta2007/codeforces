#include <stdio.h>
#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int, int>ii;
ii a[100020];
int n, l, r, c, s;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].X);
		a[i].Y = i;
	}
	sort(a, a + n);
	l = r = s = -1;
	for (int i = 0; i < n; i++) {
		if (a[i].Y != i) {
			r = i;
			l = a[i].Y;
			c++;
			if (s == -1) {
				s = l + r;
			} else if (s != l + r) {
				c = n + 1;
			}
		} else if(a[i].Y + i == s) {
			c++;
		}
	}
	if (l == -1) {
		l = r = 0;
		c = 1;
	}
	if (r - l + 1 == c) {
		printf("yes\n%d %d\n", l + 1, r + 1);
	} else {
		printf("no\n");
	}
	return 0;
}