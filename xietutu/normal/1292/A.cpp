#include <bits/stdc++.h>
using namespace std;

int n, m, sum;
int mp[2][100005];

void change(int x, int y) {
	x -= 1;
	for (int i = -1; i <= 1; ++ i) {
		if (y + i >= 1 && y + i <= n) {
			if (mp[x ^ 1][y + i] && mp[x][y]) -- sum; 
		}
	}
	mp[x][y] ^= 1;
	for (int i = -1; i <= 1; ++ i) {
		if (y + i >= 1 && y + i <= n) {
			if (mp[x ^ 1][y + i] && mp[x][y]) ++ sum; 
		}
	}

}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++ i) {
		int x, y; scanf("%d%d", &x, &y);
		change(x, y);
		if (sum == 0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}