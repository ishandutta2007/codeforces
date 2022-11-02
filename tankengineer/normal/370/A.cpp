#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int r1, c1, r2, c2, dis[8][8];

int main() {
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	int ans1 = 0, ans2 = 0, ans3 = 0;
	ans1 = 2 - (int)(r1 == r2) - (int)(c1 == c2);
	ans2 = abs(r2 - r1) == abs(c1 - c2) ? 1 : ((r1 + c1) % 2 == (r2 + c2) % 2 ? 2 : 0);
	ans3 = max(abs(r2 - r1), abs(c2 - c1));
	printf("%d %d %d\n", ans1, ans2, ans3);
	return 0;
}