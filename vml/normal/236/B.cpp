#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

const int p = 1073741824;

void expansion(int n, int *a) {
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			a[i]++;
			n /= i;
		}
	}
	if (n > 1) {
		a[n]++;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c, sum = 0;
	scanf("%d %d %d", &a, &b, &c);
	for (int i = 1; i <= a; i++) {
		int d1[100];
		for (int j = 1; j < 100; j++) {
			d1[j] = 0;
		}
		expansion(i, d1);
		for (int j = 1; j <= b; j++) {
			int d2[100];
			for (int k = 1; k < 100; k++) {
				d2[k] = d1[k];
			}
			expansion(j, d2);
			for (int k = 1; k <= c; k++) {
				int d3[100];
				for (int g = 1; g < 100; g++) {
					d3[g] = d2[g];
				}
				expansion(k, d3);
				int t = 1;
				for (int g = 1; g < 100; g++) {
					t = t * (d3[g] + 1);
				}
				sum = (sum + t) % p;
			}
		}
	}
	printf("%d", sum);
	return 0; 
}