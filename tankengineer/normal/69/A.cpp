#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

int main() {
	int n, sx, sy, sz, tx, ty, tz;
	sx = sy = sz = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d%d%d", &tx, &ty, &tz);
		sx += tx;
		sy += ty;
		sz += tz;
	}
	puts(sx == 0 && sy == 0 && sz == 0 ? "YES" : "NO");
	return 0;
}