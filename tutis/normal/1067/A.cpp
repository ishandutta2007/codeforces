/*input
3
1 -1 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll DP[5][202][2];
const ll modulo = 998244353;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll A[n];
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < 5; i++)
		for (int a = 0; a <= 201; a++)
			for (int b : {0, 1})
				DP[i][a][b] = 0;
	if (A[0] == -1)
	{
		for (int a = 1; a <= 200; a++)
			DP[0 % 5][a][0] = 1;
	}
	else
	{
		DP[0 % 5][A[0]][0] = 1;
	}
	for (int t = 1; t < n; t++)
	{
		int x = t % 5;
		int y = (t - 1) % 5;
		for (int a = 0; a <= 201; a++)
		{
			DP[x][a][0] = DP[x][a][1] = 0;
		}
		if (A[t] != -1)
		{
			for (int a = 0; a <= A[t] - 1; a++)
			{
				DP[x][A[t]][0] += DP[y][a][1];
				DP[x][A[t]][0] += DP[y][a][0];
				DP[x][A[t]][0] %= modulo;
			}
			for (int a : {A[t]})
			{
				DP[x][A[t]][1] += DP[y][a][1];
				DP[x][A[t]][1] += DP[y][a][0];
				DP[x][A[t]][1] %= modulo;
			}
			for (int a = A[t] + 1; a <= 201; a++)
			{
				DP[x][A[t]][1] += DP[y][a][1];
				DP[x][A[t]][1] %= modulo;
			}
		}
		else
		{
			for (int a = 1; a <= 200; a++)
			{
				DP[x][a + 1][0] += DP[y][a][1];
				DP[x][a + 1][0] += DP[y][a][0];
			}
			for (int a = 1; a <= 200; a++)
			{
				DP[x][0][1] += DP[y][a][1];
				DP[x][a][1] -= DP[y][a][1];
			}
			for (int a = 1; a <= 200; a++)
			{
				DP[x][a][1] += DP[y][a][1] + DP[y][a][0];
				DP[x][a + 1][1] -= DP[y][a][1] + DP[y][a][0];
			}
			for (int a = 1; a <= 201; a++)
			{
				DP[x][a][0] += DP[x][a - 1][0];
				DP[x][a][1] += DP[x][a - 1][1];
				DP[x][a][0] %= modulo;
				DP[x][a][0] += modulo;
				DP[x][a][0] %= modulo;
				DP[x][a][1] %= modulo;
				DP[x][a][1] += modulo;
				DP[x][a][1] %= modulo;
			}
			for (int a : {0, 201})
				DP[x][a][0] = DP[x][a][1] = 0;
		}
	}
	ll ans = 0;
	for (int a = 1; a <= 200; a++)
	{
		ans += DP[(n - 1) % 5][a][1];
		ans %= modulo;
	}
	cout << ans << "\n";
}