#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1001000;
int N, K;
char a[MAXN]; int z[MAXN];

void z_init () {
	int i, j, L = -1, R = -1;
	z[1] = N;
	for (i = 2; i <= N; i++) {
		if (R < i) {
			for (j = i; j <= N && a[j] == a[j - i + 1]; j++)
				z[i] = j - i + 1;
			if (z[i]) L = i, R = i + z[i] - 1;
		}
		else {
			j = i - L + 1;
			if (z[j] < R - i + 1) z[i] = z[j];
			else {
				z[i] = R - i + 1;
				for (j = R + 1; j <= N && a[j] == a[j - i + 1]; j++)
					z[i] = j - i + 1;
				L = i, R = i + z[i] - 1;
			}
		}
	}
}

int ans[MAXN];

int main () {
	scanf("%d%d", &N, &K);
	scanf("%s", a + 1);
	z_init();
	for (int i = 1; i * K <= N; i++) {
		if (z[i + 1] >= i * (K - 1)) {
			++ans[i * K];
			if (i * K + min(i, z[i * K + 1]) + 1 <= N) --ans[i * K + min(i, z[i * K + 1]) + 1];
		}
	}
	for (int i = 1, j = 0; i <= N; i++)
		j += ans[i], putchar('0' + (bool)(j));
	return 0;
}