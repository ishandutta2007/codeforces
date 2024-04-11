#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int suma = 0, sumb = 0;
	for (int i = 0; i < 3; ++i) {
		int a;
		scanf("%d", &a);
		suma += a;
	}
	for (int i = 0; i < 3; ++i) {
		int b;
		scanf("%d", &b);
		sumb += b;
	}
	int n, m = (suma + 4) / 5 + (sumb + 9) / 10;
	scanf("%d", &n);
	puts((n >= m) ? "YES" : "NO");
	return 0;
}