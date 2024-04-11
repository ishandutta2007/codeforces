#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			if (i * i + j * j == a * a) {
				int g = __gcd(i, j);
				int ti = i / g, tj = j / g;
				int k = 1;	
				while (ti * ti * k * k + tj * tj * k * k < b * b) {
					++k;
				}
				if (ti * ti * k * k + tj * tj * k * k == b * b) {
					ti *= k, tj *= k;
					if (j != ti) {
						printf("YES\n");
						printf("0 0\n%d %d\n%d %d\n", -i, j, tj, ti);
						return 0;
					}
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}