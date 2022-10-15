/*input
6 10
10 40
20 10
25 30
30 15
50 15
65 30

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(123);
const ll mod = 1000000007;
ll power(ll x, ll p)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (p)
	{
		if (p % 2 == 1)
			r = (r * x) % mod;
		p /= 2;
		x = (x * x) % mod;
	}
	return r;
}
struct point
{
	ll x, y;
	point()
	{
		x = y = 0;
	}
	point(ll a, ll b)
	{
		x = a;
		y = b;
	}
	ld r()
	{
		return sqrtl(x * x + y * y);
	}
};
point operator+(point a, point b)
{
	return point(a.x + b.x, a.y + b.y);
}
point operator-(point a, point b)
{
	return point(a.x - b.x, a.y - b.y);
}
ll cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
ld intersect(point a, point b, point c, point d)
{
	b = b - a;
	d = d - c;
	//a+xb=c+yd;
	//ad+xbd=(c+yd)d;
	//ad+xbd=cd;
	//xbd=(c-a)d;
	ld x1 = cross(c - a, d);
	ld x2 = cross(b, d);
	return x1 / x2 * b.r();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, H;
	cin >> n >> H;
	point A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i].x >> A[i].y;
	point mx = A[n - 1];
	point eye = A[n - 1] + point(0, H);
	ld ans = 0.0;
	for (int i = n - 2; i >= 0; i--)
	{
		ld d = (A[i] - A[i + 1]).r();
		if (cross(A[i] - eye, mx - eye) > 0)
		{
			ans += intersect(A[i], A[i + 1], eye, mx);
			mx = A[i];
		}
		else if (cross(A[i] - eye, mx - eye) == 0 && cross(A[i] - A[i + 1], mx - eye) <= 0)
		{
			ans += (A[i] - A[i + 1]).r();
		}
		else
		{

		}
	}
	cout << fixed << setprecision(20) << ans << "\n";
}