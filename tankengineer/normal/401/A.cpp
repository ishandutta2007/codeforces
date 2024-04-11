#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	int sum = 0;
	while (n--) {
		int a;
		scanf("%d", &a);
		sum += a;
	}
	sum = abs(sum);
	printf("%d\n", (sum + x - 1) / x);
	return 0;
}