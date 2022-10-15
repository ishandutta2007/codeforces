/***
4
0 0
0 1
1 1
1 0
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX_N 2600
ld DPi[MAX_N][MAX_N];
ld DPj[MAX_N][MAX_N];
ld x[MAX_N], y[MAX_N];
ld dist[MAX_N][MAX_N];
ll n;
ld dpi(ll i, ll j);
ld dpj(ll i, ll j);
ld dpi(ll i, ll j)
{
	if (DPi[i][j] > 0.0)
		return DPi[i][j];
	if (i == j)
	{
		DPi[i][j] = 0;
		return 0;
	}
	DPi[i][j] = max(
	                dpi((i - 1 + n) % n, j) + dist[i][(i - 1 + n) % n],
	                dpj((i - 1 + n) % n, j) + dist[i][j]
	            );
	//cout << char('A' + i) << " " << char('A' + j) << " " << DP[i][j] << endl;
	return DPi[i][j];
}
ld dpj(ll i, ll j)
{
	if (DPj[i][j] > 0.0)
		return DPj[i][j];
	if (i == j)
	{
		DPj[i][j] = 0;
		return 0;
	}
	DPj[i][j] = max(
	                dpi(i, (j + 1) % n) + dist[i][j],
	                dpj(i, (j + 1) % n) + dist[j][(j + 1) % n]
	            );
	//cout << char('A' + i) << " " << char('A' + j) << " " << DP[i][j] << endl;
	return DPj[i][j];
}
ld anss(ll i)
{
	return max(dpi(i, (i + 1) % n), dpj(i, (i + 1) % n));
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = sqrtl((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_N; j++)
			DPi[i][j] = -1;
	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_N; j++)
			DPj[i][j] = -1;
	ld ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, anss(i));
	cout << fixed << setprecision(30) << ans << endl;
}