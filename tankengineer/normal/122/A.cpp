#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

bool luck(const int i) {
	int a = i;
	while (a) {
		if (a % 10 != 4 && a % 10 != 7) return false;
		a /= 10;
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		if (luck(i) && n % i == 0) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}