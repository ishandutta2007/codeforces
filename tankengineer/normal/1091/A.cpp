#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int y, b, r;
	scanf("%d%d%d", &y, &b, &r);
	int s = min(y, min(b - 1, r - 2)), 
		ans = s * 3 + 3;
	printf("%d\n", ans);
	return 0;
}