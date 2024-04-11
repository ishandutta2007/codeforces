#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

#define P1 1000000007
#define P2 1000000009
#define Q1 37
#define Q2 107
#define N 210000

int n, m, pre[N], now[N], hash1[N], pow1[N], pow2[N], inv1[N], inv2[N], hash2[N];
char S[N];
int ne[N][26];

int Pow(int x, int y, int P) {
	int ans = 1;
	for (int i = 1; i <= y; i *= 2, x = 1LL * x * x % P)
		if (i & y)
			ans = 1LL * ans * x % P;
	return ans;
}

int calc(int *hash, int P, int Q, int *inv, int *pow, int l, int r) {
	int tmp = 1LL * (hash[r] - hash[l - 1]) * inv[l - 1] % P;
	tmp = (tmp - 1LL * (1 - pow[r - l + 1]) % P * Pow(1 - Q, P - 2, P) % P * (l - 1)) % P;
	for (int i = 0; i < 26; i++) {
		int it = ne[l][i];
		if (it <= r) {
			// printf("%d %d\n", i, it);
			tmp = (tmp - 1LL * (pre[it] - (l - 1)) * pow[it - l]) % P;
		}
	}
	return (tmp + P) % P;
}

int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", S + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = now[S[i] - 'a'];
		now[S[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++)
		now[i] = n + 1;
	for (int i = n; i; i--) {
		now[S[i] - 'a'] = i;
		for (int j = 0; j < 26; j++)
			ne[i][j] = now[j];
	}


	inv1[0] = 1;
	inv1[1] = Pow(Q1, P1 - 2, P1);
	for (int i = 2; i <= n; i++)
		inv1[i] = 1LL * inv1[i - 1] * inv1[1] % P1;
	pow1[0] = 1;
	for (int i = 1; i <= n; i++)
		pow1[i] = 1LL * pow1[i - 1] * Q1 % P1;

	inv2[0] = 1;
	inv2[1] = Pow(Q2, P2 - 2, P2);
	for (int i = 2; i <= n; i++)
		inv2[i] = 1LL * inv2[i - 1] * inv2[1] % P2;
	pow2[0] = 1;
	for (int i = 1; i <= n; i++)
		pow2[i] = 1LL * pow2[i - 1] * Q2 % P2;

	for (int i = 1; i <= n; i++) {
		hash1[i] = (hash1[i - 1] + 1LL * pre[i] * pow1[i - 1]) % P1;
		hash2[i] = (hash2[i - 1] + 1LL * pre[i] * pow2[i - 1]) % P2;
	}


	while (m--) {
		int x, y, len;
		scanf("%d%d%d", &x, &y, &len);
		// printf("%d %d\n", calc(hash1, P1, Q1, inv1, pow1, x, x + len - 1), calc(hash1, P1, Q1, inv1, pow1, y, y + len - 1));
		if (calc(hash1, P1, Q1, inv1, pow1, x, x + len - 1) == calc(hash1, P1, Q1, inv1, pow1, y, y + len - 1)
			&& calc(hash2, P2, Q2, inv2, pow2, x, x + len - 1) == calc(hash2, P2, Q2, inv2, pow2, y, y + len - 1))
			printf("YES\n");
		else
			printf("NO\n");
	}
}