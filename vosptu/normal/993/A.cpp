#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <cmath>
using namespace std;

int x[10], y[10], tx[10], ty[10];

int kk(int x[], int y[], int i, int j) {
	int sum = 0;
	for (int k = 0; k < 4; k++)
		sum += abs((x[k] - i) * (y[k + 1] - j) - (x[k + 1] - i) * (y[k] - j));
	return abs(sum);
}

bool in(int x[], int y[], int i, int j) {
	// for ()
	x[4] = x[0];
	y[4] = y[0];
	return kk(x, y, x[0], y[0]) == kk(x, y, i, j);
}

int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d%d", &x[i], &y[i]);
		x[i] *= 2; y[i] *= 2;
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d%d", &tx[i], &ty[i]);
		tx[i] *= 2; ty[i] *= 2;
	}
	for (int i = -300; i <= 300; i++)
		for (int j = -300; j <= 300; j++) {
			if (in(x, y, i, j) && in(tx, ty, i, j)) {
				// printf("? %d %d\n", i, j);
				printf("YES\n");
				return 0;
			}
		}
	printf("NO\n");
}