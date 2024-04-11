#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, m, x;
	scanf("%d%d%d", &n, &m, &x);
	if (x * 2 - 1 > min(n, m)) {
		printf("%d\n", 0);
	} else {
		int area1 = ((n - (x - 1) * 2) * (m - (x - 1) * 2) + 1) / 2,
			area2 = min(n, m) > x * 2 ? ((n - x * 2) * (m - x * 2) + 1) / 2 : 0;
		printf("%d\n", area1 - area2);
	}
	return 0;
}