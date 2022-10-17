#include <cstdio>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	int n;
	while (t--) {
		scanf("%d", &n);
		int odd = 0;
		int inc = 0;
		int v;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &v);
			if (v & 1) ++odd;
			if ((v & 1) != (i & 1)) ++inc;
		}
		if (odd != n / 2) printf("-1\n");
		else printf("%d\n", inc / 2);
	}
	return 0;
}