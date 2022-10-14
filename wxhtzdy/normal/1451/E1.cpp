#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 16) + 5;
int n;
int a[N];
int ans[N];

int askAnd(int i, int j) {
	printf("AND %d %d\n", i, j);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

int askOr(int i, int j) {
	printf("OR %d %d\n", i, j);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

int askXor(int i, int j) {
	printf("XOR %d %d\n", i, j);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

void solve(int i, int j) {
	int v = askAnd(i, j);
	ans[i] = v;
	ans[j] = v;
	ans[1] = ans[i] ^ a[i];
	for (int x = 2; x <= n; x++) {
		if (x == i || x == j) {
			continue;
		}
		ans[x] = a[x] ^ ans[1];
	}
	printf("! ");
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	fflush(stdout);
	exit(0);
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		a[i] = askXor(1, i);
	map<int, int> mapchik;
	mapchik[0] = 1;
	for (int i = 2; i <= n; i++) {
		if (mapchik.count(a[i])) {
			solve(mapchik[a[i]], i);
		}
		mapchik[a[i]] = i;
	}
	int x, y;
	for (int i = 2; i <= 3; i++) {
		for (int j = i + 1; j <= n; j++) {
			if ((a[i] ^ a[j]) == (n - 1)) {
				x = i;
				y = j;
			}
		}
	}
	int xorAB = a[x];
	int xorAC = a[y];
	int xorBC = a[x] ^ a[y];
	int andAB = askAnd(1, x);
	int andAC = askAnd(1, y);
	int andBC = 0;
	int V1 = xorAB + 2 * andAB;
	int V2 = xorAC + 2 * andAC;
	int V3 = xorBC + 2 * andBC;
	ans[1] = (V1 + V2 - V3) / 2;
	for (int i = 2; i <= n; i++) {
		ans[i] = ans[1] ^ a[i];
	}
	printf("! ");
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	fflush(stdout);
	return 0;
}