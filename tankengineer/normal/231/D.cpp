#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int x1, y1, z1, x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	scanf("%d%d%d", &x1, &y1, &z1);
	int a[6];
	for (int i = 0; i < 6; ++i) {
		scanf("%d", a + i);
	}
	int ans = 0;
	ans += (x > x1) * a[5];
	ans += (y > y1) * a[1];
	ans += (z > z1) * a[3];
	ans += (x < 0) * a[4];
	ans += (y < 0) * a[0];
	ans += (z < 0) * a[2];
	printf("%d\n", ans);
	return 0;
}