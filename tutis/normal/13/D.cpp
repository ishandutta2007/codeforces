/*input
4 1
-1 -1000000000
0 1000000000
2 1
-2 1
0 0
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct point
{
	ll x, y;
	point() {}
	point(ll x, ll y): x(x), y(y) {}
	bool operator<(const point &o)const
	{
		if (x != o.x)
			return x < o.x;
		return y < o.y;
	}
	ld kampas()
	{
		ld ret = atan2(y, x);
		if (y < 0)
			ret += 10;
		return ret;
	}
};
point operator!(const point &a)
{
	return point(a.x, -a.y);
}
point operator+(const point &a, const point &b)
{
	return point(a.x + b.x, a.y + b.y);
}
point operator-(const point &a, const point &b)
{
	return point(a.x - b.x, a.y - b.y);
}
point operator*(const point &a, const point &b)
{
	return point(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
point operator*(const point &a, ll k)
{
	return point(a.x * k, a.y * k);
}
point operator/(const point &a, ll k)
{
	return point(a.x / k, a.y / k);
}
ll dot(const point &a, const point &b)
{
	return a.x * b.x + a.y * b.y;
}
ll cross(const point &a, const point &b)
{
	return a.x * b.y - a.y * b.x;
}
ll sgn(ll x)
{
	if (x < 0)
		return -1;
	if (x > 0)
		return 1;
	return 0;
}
bool x(point a, point b, point c, point d)
{
	return sgn(cross(b - a, c - a)) * sgn(cross(b - a, d - a)) == -1 &&
	       sgn(cross(d - c, a - c)) * sgn(cross(d - c, b - c)) == -1;
}
point R[500];
point B[500];
int K[500][500];
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> R[i].x >> R[i].y;
	for (int i = 0; i < m; i++)
		cin >> B[i].x >> B[i].y;
	mt19937 gen(time(NULL));
	int dx = gen();
	int dy = gen();
	for (int i = 0; i < n; i++)
	{
		R[i].x += dx;
		R[i].y += dy;
	}
	for (int i = 0; i < m; i++)
	{
		B[i].x += dx;
		B[i].y += dy;
	}
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < n; b++)
		{
			if (cross(R[a], R[b]) <= 0)
				continue;
			for (int c = 0; c < m; c++)
			{
				if (cross(B[c] - R[b], R[b] - R[a]) < 0 &&
				        cross(B[c], R[b]) > 0 &&
				        cross(B[c], R[a]) < 0)
					K[a][b]++;
			}
			K[b][a] = -K[a][b];
		}
	}
	int ans = 0;
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < a; b++)
		{
			for (int c = 0; c < b; c++)
			{
				if (K[a][b] + K[b][c] + K[c][a] == 0)
				{
					ans++;
				}
			}
		}
	}
	cout << ans << "\n";
}