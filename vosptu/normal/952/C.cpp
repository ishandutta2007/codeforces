#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
// #include <isstream>
using namespace std;

int n;
int a[110];

bool check(int k) {
	for (int i = 1; i < k; i++)
		if (abs(a[i] - a[i + 1]) >= 2)
			return false;
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = n; i; i--) {
		if (!check(i)) {
			printf("NO\n");
			return 0;
		}
		int ma = 1;
		for (int j = 1; j <= i; j++)
			if (a[j] > a[ma])
				ma = j;
		for (int j = ma; j < i; j++)
			a[j] = a[j + 1];
	}
	printf("YES\n");
}