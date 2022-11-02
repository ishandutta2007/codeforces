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
#include <list>
using namespace std;

int n, a[110000], sg[110000], tx[110000];
bool used[110000];

bool cmp(int x, int y) {
	return a[x] < a[y];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		tx[i] = i;
	sort(tx + 1, tx + n + 1, cmp);

	sg[tx[n]] = 0;
	for (int i = n - 1; i >= 1; i--) {
		for (int j = tx[i] % a[tx[i]]; j <= n; j += a[tx[i]])
			if (j != tx[i] && a[j] > a[tx[i]])
				used[sg[j]] = true;
		while (used[sg[tx[i]]])
			sg[tx[i]]++;
		for (int j = tx[i] % a[tx[i]]; j <= n; j += a[tx[i]])
			if (j != tx[i] && a[j] > a[tx[i]])
				used[sg[j]] = false;
	}
	for (int i = 1; i <= n; i++)
		if (sg[i])
			printf("A");
		else
			printf("B");
	printf("\n");
}