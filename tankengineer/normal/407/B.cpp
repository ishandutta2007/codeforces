#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005, MOD = 1000000007;

int f[N];

int main() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		--p;
		if (p == i) {
			f[i] = 2;
		} else {
			for (int j = p; j < i; ++j) {
				(f[i] += f[j]) %= MOD;
			}
			(f[i] += 2) %= MOD;
		}
		(ans += f[i]) %= MOD;
	}
	printf("%d\n", ans);
	return 0;
}