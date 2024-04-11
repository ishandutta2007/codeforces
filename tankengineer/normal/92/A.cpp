#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, left, i = 0;
	scanf("%d%d", &n, &left);
	while (left > i) {
		left -= i + 1;
		(++i) %= n;
	}
	printf("%d\n", left);
	return 0;
}