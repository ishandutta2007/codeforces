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

int x, y, X, Y;
bool used[1100][1100];
int n;
int tx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, ty[8] = {1, 0, -1, 1, -1, 1, 0, -1};

void dfs(int x, int y) {
	if (X == x || y == Y || abs(x - X) == abs(y - Y))
		return ;
	if (used[x][y])
		return ;
	used[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int xx = x + tx[i], yy = y + ty[i];
		if (1 <= xx && xx <= n && 1 <= yy && yy <= n)
			dfs(xx, yy);
	}
}

int main() {
	scanf("%d", &n);
	scanf("%d%d", &X, &Y);
	scanf("%d%d", &x, &y);
	dfs(x, y);
	scanf("%d%d", &x, &y);
	if (used[x][y])
		printf("YES\n");
	else
		printf("NO\n");
}