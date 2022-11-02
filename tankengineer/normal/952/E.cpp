#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int main() {
	int m;
	scanf("%d", &m);
	int cw = 0, cb = 0;
	for (int i = 0; i < m; ++i) {
		char text[15];
		scanf("%*s%s", text);
		if (text[0] == 's') {
			++cw;
		} else {
			++cb;
		}
	}
	int n = 1;
	if (cb > cw) {
		swap(cb, cw);
	}
	while ((n * n + 1) / 2 < cw || n * n / 2 < cb) {
		++n;
	}
	printf("%d\n", n);
	return 0;
}