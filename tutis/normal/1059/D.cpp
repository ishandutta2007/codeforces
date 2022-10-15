/*input
2
0 1
0 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<typename T>
T ABS(T x)
{
	if (x > 0)
		return x;
	return -x;
}
int main()
{
	clock_t pradzia = clock();
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	ld x[n], y[n];
	bool A[2] = {false, false};
	ld lo = 0;
	ld hi = 2e16;
	for (int i = 0; i < n; i++)
	{
		ll X, Y;
		cin >> X >> Y;
		x[i] = X;
		A[Y > 0] = true;
		y[i] = abs(Y);
		lo = max(lo, y[i] * 0.5);
	}
	if (A[0] && A[1])
	{
		cout << "-1\n";
		return 0;
	}
	while (double(clock() - pradzia) / CLOCKS_PER_SEC <= 1.7)
	{
		ld Y = (lo + hi) * 0.5;
		ld mini = 1e150;
		ld maxi = -1e150;
		for (int i = 0; i < n; i++)
		{
			ld dx = sqrtl(ABS(- y[i] * y[i] + 2 * y[i] * Y));
			mini = min(mini, x[i] + dx);
			maxi = max(maxi, x[i] - dx);
		}
		if (mini >= maxi)
			hi = Y;
		else
			lo = Y;
	}
	cout << fixed << setprecision(25) << (long double)((lo + hi) * 0.5) << "\n";
}