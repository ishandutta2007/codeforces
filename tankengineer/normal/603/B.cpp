#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;

int p, k;

int powMod(int a, int n) {
	int ret = 1;
	while (n) {
		if (n & 1) {
			ret = (long long)ret * a % MOD;
		}
		a = (long long)a * a % MOD;
		n >>= 1;
	}
	return ret;
}

const int N = 1000005;

bool vis[N];

int main() {
	scanf("%d%d", &p, &k);
	if (k == 0) {
		printf("%d\n", powMod(p, p - 1));
	} else if (k == 1) {
		printf("%d\n", powMod(p, p));
	} else {
		int ans = 1;
		for (int i = 1; i < p; ++i) {
			if (vis[i]) {
				continue;
			}
			int u = i;
			while (!vis[u]) {
				vis[u] = true;
				u = (long long)u * k % p;
			}
			ans = (long long)ans * p % MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}