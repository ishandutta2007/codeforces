/**
4 68
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PI (3.14159265358979323846264338327950288419716939)
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, a;
	ld ang;
	cin >> n >> ang;
	ld x[n], y[n];
	for (int i = 0; i < n; i++)
		x[i] = cosl(ld(i) / ld(n) * 2.0 * PI);
	for (int i = 0; i < n; i++)
		y[i] = sinl(ld(i) / ld(n) * 2.0 * PI);
	ld mins = 180.0;
	int A = 0, B = 0, C = 0;
	for (int i = 1; i <= n - 2; i++)
	{
		int lo = i + 1;
		int hi = n - 1;
		while (lo < hi)
		{
			int k = (lo + hi) / 2;
			ld a = sqrtl(pow(x[0] - x[i], 2) + pow(y[0] - y[i], 2));
			ld b = sqrtl(pow(x[k] - x[i], 2) + pow(y[k] - y[i], 2));
			ld c = sqrtl(pow(x[0] - x[k], 2) + pow(y[0] - y[k], 2));
			ld K = acos((a * a + b * b - c * c) / (2.0 * a * b));
			K = K * 180.0 / PI;
			if (K < a)
				lo = k + 1;
			else
				hi = k;
			ld sk = abs(ang - K);
			if (sk <= mins)
			{
				sk = mins;
				int A = 0;
				int B = i;
				int C = k;
			}
		}
		int k = (lo + hi) / 2;
		ld a = sqrtl(pow(x[0] - x[i], 2) + pow(y[0] - y[i], 2));
		ld b = sqrtl(pow(x[k] - x[i], 2) + pow(y[k] - y[i], 2));
		ld c = sqrtl(pow(x[0] - x[k], 2) + pow(y[0] - y[k], 2));
		ld K = acos((a * a + b * b - c * c) / (2.0 * a * b));
		K = K * 180.0 / PI;
		if (K - a >= 1e-12)
			lo = k;
		else
			hi = k + 1;
		ld sk = abs(ang - K);
		if (sk <= mins)
		{
			mins = sk;
			A = 0;
			B = i;
			C = k;
		}
	}
	cout << A + 1 << " " << B + 1 << " " << C + 1;
}