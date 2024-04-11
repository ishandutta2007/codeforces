#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int dx[] = {0, 0, -1, 1, 0}, dy[] = {-1, 1, 0, 0, 0};

int main() {
	int a[3][3];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	int b[3][3];
	memset(b, 0, sizeof(b));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			b[i][j] = 1;
			for (int d = 0; d < 5; ++d) {
				int tx = i + dx[d], ty = j + dy[d];
				if (tx >= 0 && tx < 3 && ty >= 0 && ty < 3) {
					b[i][j] += a[tx][ty];
				}
			}
			b[i][j] &= 1;
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%d", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}