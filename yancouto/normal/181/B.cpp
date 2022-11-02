#include <bits/stdc++.h>
using namespace std;

int g[2100][2100];
int x[3100], y[3100];
int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		g[x[i] + 1010][y[i] + 1010] = 1;
	}
	int tot = 0;
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++) {
			if((x[i] + x[j]) & 1) continue;
			if((y[i] + y[j]) & 1) continue;
			int xx = (x[i] + x[j]) / 2;
			int yy = (y[i] + y[j]) / 2;
			if(g[xx + 1010][yy + 1010]) tot++;
		}
	printf("%d\n", tot);
}