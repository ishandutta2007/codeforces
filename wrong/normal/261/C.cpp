#include <iostream>
#include <algorithm>

using namespace std;

typedef long long Int;

Int doit(Int n, Int x)
{
	Int dp[50][50][2] = {{}};
	int nb[50];

	int m = 0;
	while (n > 0) {
		nb[m++] = n % 2;
		n >>= 1;
	}
	reverse(nb, nb+m);

	dp[0][0][1] = 1;
	for (int i = 0; i < m; ++i) {
		for (int c = 0; c <= i; ++c) {
			dp[i + 1][c][0] += dp[i][c][0];
			dp[i + 1][c][nb[i] == 0] += dp[i][c][1];
			dp[i + 1][c + 1][0] += dp[i][c][0];
			if (nb[i] == 1) {
				dp[i + 1][c + 1][1] += dp[i][c][1];
			}
		}
	}

	return dp[m][x][0] + dp[m][x][1];
}

int main()
{
	Int n, t;

	cin >> n >> t;

	Int x = 0;
	while (t > 1LL << x) {
		++x;
	}

	if (t == 1 << x) {
		++x;
		Int res = doit(n + 1, x);
		if (x == 1) {
			--res;
		}
		cout << res << endl;
	} else {
		cout << 0 << endl;
	}

	return 0;
}