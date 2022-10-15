/***
0.000000 0.000000
1.000000 1.000000
0.000000 1.000000
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define eps (1e-3)
struct point
{
	ld x, y;
	point() {}
	point(ld x, ld y): x(x), y(y) {}
};
ld dist(point a, point b)
{
	return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}
#define PI (-2*atan2(-1, 0))
int main()
{
	point M[3];
	for (int i = 0; i < 3; i++)
		cin >> M[i].x >> M[i].y;
	ld Add = dist(M[0], M[1]);
	ld Bdd = dist(M[1], M[2]);
	ld Cdd = dist(M[2], M[0]);
	ld ans = DBL_MAX;
	for (int t = 3; t <= 100; t++)
	{
		point A[t];
		for (int l = 0; l < t; l++)
			A[l] = point(cosl(2 * PI * ld(l + 1) / ld(t)), sinl(2 * PI * ld(l + 1) / ld(t)));
		int a = 0;
		for (int b = 1; b < t; b++)
		{
			for (int c = 1; c < t; c++)
			{
				ld Ad = Add / dist(A[b], A[c]);
				ld Bd = Bdd / dist(A[a], A[c]);
				ld Cd = Cdd / dist(A[a], A[b]);
				if (abs(Ad - Bd) <= eps && abs(Ad - Cd) <= eps)
				{
					ans = min(ans, Ad * sinl(2.0 * PI / ld(t)) * ld(t) / 2.0);
				}
			}
		}
	}
	cout << fixed << setprecision(10) << ans;
}