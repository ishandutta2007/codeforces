#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <list>
using namespace std;

#define N 1100000
#define P 1000000007

int n, q[N], len, len2;
vector <int> ve[N], V[N];
map <long long, int> ind;
long long X[N], p[N], a[N], SS[N];
int dp[N];

void dfs(int x, long long A, long long B) {
	if (x > len) {
		V[ind[A]].push_back(ind[B]);
	}else {
		for (int a = 0; a <= q[x]; a++, A *= p[x], B *= p[x]) {
			long long BB = B;
			for (int b = a; b <= q[x]; b++, BB *= p[x])
				dfs(x + 1, A, BB);
		}
	}
}

long long gcd(long long x, long long y) {
	if (!x)
		return y;
	return gcd(y % x, x);
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);

	for (int i = 1; i < n; i++) {
		int x;
		scanf("%d", &x);
		ve[x].push_back(i + 1);
	}
	for (int i = n; i; i--)
		for (int j = 0; j < (int) ve[i].size(); j++)
			a[i] += a[ve[i][j]];

	long long S = a[1];
	for (long long i = 2; i * i <= S; i++)
		if (S % i == 0) {
			len++;
			p[len] = i;
			q[len] = 0;
			while (S % i == 0) {
				q[len]++;
				S /= i;
			}
		}
	if (S > 1) {
		p[++len] = S;
		q[len] = 1;
	}
	for (long long i = 1; i * i <= a[1]; i++)
		if (a[1] % i == 0) {
			X[++len2] = i;
			if (i * i != a[1]) {
				X[++len2] = a[1] / i;
			}
		}
	sort(X + 1, X + len2 + 1);
	for (int i = 1; i <= len2; i++)
		ind[X[i]] = i;

	dfs(1, 1, 1);
	for (int i = 1; i <= n; i++) {
		SS[ind[gcd(a[1], a[i])]]++;
	}

	
	for (int i = 1; i <= len2; i++) {
		long long tot = 0;
		for (int j = 0; j < (int) V[i].size(); j++)
			tot += SS[V[i][j]];
		if (tot == a[1] / X[i])
			dp[i] = 1;
		else
			dp[i] = 0;
	}

	for (int i = 1; i <= len2; i++) {
		for (int j = 0; j < (int) V[i].size(); j++)
		if (i != V[i][j] && dp[V[i][j]])
			dp[V[i][j]] = (dp[V[i][j]] + dp[i]) % P;
	}
	printf("%d\n", dp[len2]);
}