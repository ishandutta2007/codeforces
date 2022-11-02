#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	int in = (n - 1) * (m - 1);
	int mul = n * m - in + 1;
	int ans = 1;
	for (int i = 1; i <= mul; i++)
		ans = ans * 2 % P;
	printf("%d\n", ans);
}