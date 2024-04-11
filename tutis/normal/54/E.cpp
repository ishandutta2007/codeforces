/*input
5
1 0
4 1
3 5
1 5
0 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct point
{
	ll x, y;
	point()
	{

	}
	point(ll x, ll y): x(x), y(y)
	{

	}
	ll ilg2()
	{
		return (x * x + y * y);
	}
};
point operator-(point a, point b)
{
	return point(a.x - b.x, a.y - b.y);
}
point operator*(point a, point b)
{
	return point(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
ll cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
ll dot(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}
pair<ld, ld> f(point a, point b)
{
	return {ld(cross(a, b))*ld(dot(a, b)), a.ilg2()};
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll N;
	cin >> N;
	point A[N];
	for (int i = 0; i < N; i++)
		cin >> A[i].x >> A[i].y;
	ll plot = 0;
	for (int i = 0; i < N; i++)
	{
		plot += cross(A[i], A[(i + 1) % N]);
	}
	if (plot < 0)
	{
		for (int i = 0; i < N; i++)
			A[i] = point(-A[i].x, A[i].y);
	}
	pair<ld, ld>ans = {2e18, 1};
	for (int rev = 0; rev < 2; rev++)
	{
		ll plotsum = 0;
		int j = 0;
		for (int i = 0; i < N; i++)
		{
			plotsum -= cross(A[i], A[(i + 1 + N) % N]);
			point x = A[(i + 1) % N] - A[i];
			x = x * point(0, 1);
			while (cross(x, point(A[(j + 1) % N] - A[(j) % N])) <= 0)
			{
				plotsum += cross(A[j], A[(j + 1) % N]);
				j = (j + 1) % N;
			}
			ll plotas2 = plotsum - cross(A[(i + 1) % N], A[j]);
			pair<ld, ld>F = f(A[(i + 1) % N] - A[i], A[j] - A[(i + 1) % N]);
			F.first -= plotas2 * F.second;
			if (ld(ans.first) * ld(F.second) >= ld(F.first) * ld(ans.second))
				ans = F;
		}
		reverse(A, A + N);
		for (int i = 0; i < N; i++)
			A[i] = point(-A[i].x, A[i].y);
	}
	cout << fixed << setprecision(30) << ld(ans.first) / ld(ans.second * 2ll) << "\n";
}