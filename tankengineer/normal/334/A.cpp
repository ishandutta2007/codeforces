#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int tmp = 0;
			if (j & 1) {
				tmp = j * n + i + 1;
			} else {
				tmp = j * n + n - i;
			}
			printf("%d%c", tmp, j == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}