#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 16;

int n;

int r[N], m[N];

int main() {
	scanf("%d", &n);
	long long lcm = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", m + i);
		if (!lcm) {
			lcm = m[i];
		} else {
			lcm = lcm * m[i] / __gcd((int)(lcm % m[i]), m[i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", r + i);
	}
	double ans = 0;
	for (int i = 0; i < lcm; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i % m[j] == r[j]) {
				ans += 1;
				break;
			}
		}
	}
	printf("%.12f\n", ans / lcm);
	return 0;
}