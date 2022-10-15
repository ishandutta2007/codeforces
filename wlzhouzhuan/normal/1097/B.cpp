#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

#define RE register
#define rep(i, l, r) for (RE int i = l; i <= r; i++)
#define rep2(i, l, r) for (RE int i = l; i >= r; i--)

int s[20][500];
int a[20];
int n;

int main() {
	scanf("%d", &n);
	s[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j < 360; j++) {
			int p1 = j - a[i], p2 = j + a[i];
			p1 = (p1 + 1080) % 360, p2 = (p2 + 1080) % 360;
			if (s[i - 1][j]) s[i][p1] = s[i][p2] = 1;
		}
	}
	if (s[n][0]) printf("YES\n");
	else printf("NO\n");
	return 0;
}