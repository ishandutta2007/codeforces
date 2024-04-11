#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, m, c;
	scanf("%d%d%d", &n, &m, &c);
	printf("%d\n", m * (m - 1) / 2);
	if (c == 0) {
		for (int i = 1; i <= m; ++i) {
			for (int j = i + 1; j <= m; ++j) {
				printf("%d %d\n", i, j);
			}
		}
	} else {
		for (int i = m; i >= 1; --i) {
			for (int j = i - 1; j >= 1; --j) {
				printf("%d %d\n", i, j);
			}
		}
	}
	return 0;
}