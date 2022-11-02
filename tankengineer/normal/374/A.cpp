#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

long long INF = 1ll << 60;
long long n, m, i, j, a, b;

long long solve(long long n, long long m, long long i, long long j) {
	if (i % a != 0 || j % b != 0) {
		return INF;
	}
	if (1 + a > n || 1 + b > m) {
		if (i != 0 || j != 0) {
			return INF;
		}
	}
	long long k1 = i / a, k2 = j / b;
	if ((k1 ^ k2) & 1) {
		return INF;
	}
	return max(k1, k2);
}

int main() {
	cin >> n >> m >> i >> j >> a >> b;
	long long ans = min(min(solve(n, m, i - 1, j - 1), solve(n, m, n - i, j - 1)), min(solve(n, m, i - 1, m - j), solve(n, m, n - i, m - j)));
	if (ans == INF) {
		puts("Poor Inna and pony!");
	} else {
		cout << ans << endl;
	}
	return 0;
}