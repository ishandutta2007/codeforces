#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int solve(int a, int b, int left) {
	if (a == 0 && left < b) {
		return 0;
	}
	int ret = a;
	left += a;
	ret += solve(left / b, b, left % b);
	return ret;
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", solve(a, b, 0));
	return 0;
}