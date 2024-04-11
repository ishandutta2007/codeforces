#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int gcd(const int a, const int b) {return b == 0 ? a : gcd(b, a % b);}
int main() {
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);
	while (n) {
		n -= gcd(a, n);
		if (n == 0) {
			printf("0\n");
			return 0;
		}
		n -= gcd(b, n);
		if (n == 0) {
			printf("1\n");
			return 0;
		}
	}
	return 0;
}