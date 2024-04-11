#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long double ld;

const int N = 103;
int a, b, c;
ld dp[N][N][N];

void eval(int x, int y, int z)
{
	if (x + y + z == max(x, max(y, z))) return;
	int cnt = x * y + x * z + y * z;
	if (cnt == 0) throw;
	if (x != 0) dp[x - 1][y][z] += dp[x][y][z] * (ld)(x * z) / (ld)cnt;
	if (y != 0) dp[x][y - 1][z] += dp[x][y][z] * (ld)(x * y) / (ld)cnt;
	if (z != 0) dp[x][y][z - 1] += dp[x][y][z] * (ld)(y * z) / (ld)cnt;
	return;
}

int main()
{
	cin >> a >> b >> c;
	dp[a][b][c] = 1.;
	for (int x = N - 2; x >= 0; x--)
		for (int y = N - 2; y >= 0; y--)
			for (int z = N - 2; z >= 0; z--)
				eval(x, y, z);
	
	ld ans = 0.;
	for (int i = 1; i < N; i++)
		ans += dp[i][0][0];
	printf("%.14lf ", (double)ans);
	ans = 0.;
	for (int i = 1; i < N; i++)
		ans += dp[0][i][0];
	printf("%.14lf ", (double)ans);
	ans = 0.;
	for (int i = 1; i < N; i++)
		ans += dp[0][0][i];
	printf("%.14lf\n", (double)ans);

	return 0;
}