#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	int64_t p;
	cin >> N >> p;
	long double A[N], B[N];
	int64_t sumA = 0;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		sumA += a;
		A[i] = a;
		B[i] = b;
	}
	if (sumA <= p)
	{
		cout << -1;
		return 0;
	}
	long double P = p;
	long double low = 0;
	long double hi = 2e10;
	while (abs(low - hi) > 0.000000001)
	{
		long double l = (low + hi) / 2.0;
		long double l1 = 0;
		for (int i = 0; i < N; i++)
		{
			if (l * A[i] - B[i] > 0)
				l1 += (l * A[i] - B[i]) / P;
		}
		if (l1 >= l)
			hi = l;
		else
			low = l;
	}
	cout << fixed << setprecision(20) << low << "\n";
	return 0;
}