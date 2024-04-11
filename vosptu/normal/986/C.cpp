#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <ctime>
using namespace std;

int n, m;
int a[1 << 23], fa[1 << 23], used[1 << 23], ok[1 << 23], sum[1 << 23];
bool op = false;

int gf(int x) {
	if (fa[x] == x)
		return fa[x];
	else
		return fa[x] = gf(fa[x]);
}

void add(int x, int y) {
	if (op && x >= (1 << n) && !sum[x - (1 << n)])
		return ;
	if (op && y >= (1 << n) && !sum[y - (1 << n)])
		return ;
	
	// printf("?? %d %d\n", x, y);
	x = gf(x);
	y = gf(y);
	fa[y] = x;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < (1 << (n + 1)); i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &a[i]);
		add(a[i], a[i] + (1 << n));
		sum[a[i]] = 1;
	}
	op = true;
	for (int i = 0; i < (1 << n); i++)
		for (int j = 0; j < n; j++)
			if (i & (1 << j))
				sum[i] |= sum[i ^ (1 << j)];
	
	for (int i = 1; i <= m; i++) {
		ok[((1 << n) - 1) ^ a[i]] = true;
		add(a[i], (((1 << n) - 1) ^ a[i]) + (1 << n));
	}
	for (int i = (1 << n) - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++)
			ok[i] |= ok[i | (1 << j)];
	}

	for (int i = 0; i < (1 << n); i++)
		if (ok[i]) {
			// printf("ok %d\n", i);
			for (int j = 0; j < n; j++)
				if (i & (1 << j))
					add(i + (1 << n), i - (1 << j) + (1 << n));
		}
	for (int i = 1; i <= m; i++)
		used[gf(a[i])] = true;
	int ans = 0;
	for (int i = 0; i < (1 << (n + 1)); i++)
		if (used[i])
			ans += 1;
	printf("%d\n", ans);
}