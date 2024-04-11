#include <bits/stdc++.h>
using namespace std;
class point
{
public:
	long double x, y;
	point(long double x, long double y): x(x), y(y) {}
	point() {}
};
long double dist(point a, point b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
long double area(point A, point B, point C)
{
	long double a = dist(B, C);
	long double b = dist(A, C);
	long double c = dist(B, A);
	long double p = (a + b + c) / 2;
	return sqrtl(p * (p - a) * (p - b) * (p - c));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	point a[N + 3];
	for (int i = 0; i < N; i++)
		cin >> a[i].x >> a[i].y;
	a[N] = a[0];
	a[N + 1] = a[1];
	a[N + 2] = a[2];
	long double D2 = 40000000000;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				continue;
			D2 = min(D2, dist(a[i], a[j]));
		}
	}
	long double D = D2 / 2.0;
	for (int i = 1; i <= N; i++)
	{
		long double ar = area(a[i], a[i - 1], a[i + 1]);
		long double b = dist(a[i - 1], a[i + 1]);
		long double h = 2 * ar / b;
		D = min(D, h / 2.0);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == (j % N) or i == (j + 1) % N)
				continue;
			long double ar = area(a[i], a[j], a[j + 1]);
			long double b = dist(a[j], a[j + 1]);
			long double h = 2 * ar / b;
			D = min(D, h / 2.0);
		}
	}
	cout << fixed << setprecision(20) << D << endl;
	return 0;
}