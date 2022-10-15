/***
2
0 0.5
0.5 0
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	ld A[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	int full = 0;
	for (int i = 0; i < n; i++)
		full += (1 << (i));
	ld P[full + 1];
	for (int i = 0; i <= full; i++)
		P[i] = 0;
	P[full] = 1;
	for (int mask = full; mask >= 0; mask--)
	{
		ld kiek = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (((mask & (1 << i)) != 0) && ((mask & (1 << j)) != 0))
					kiek += 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
				if (((mask & (1 << i)) != 0) && ((mask & (1 << j)) != 0))
				{
					P[mask ^ (1 << i)] += P[mask] * A[j][i] / kiek;
					P[mask ^ (1 << j)] += P[mask] * A[i][j] / kiek;
				}
		}
	}
	for (int i = 0; i < n; i++)
		cout << fixed << setprecision(10) << P[1 << i] << " ";
}