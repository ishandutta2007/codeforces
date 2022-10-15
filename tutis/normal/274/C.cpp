/*input
4
0 0
4 8
8 0
4 3
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
struct point
{
	ld x, y;
	point()
	{
		x = y = 0;
	}
	point(ld a, ld b)
	{
		x = a;
		y = b;
	}
	ld r()
	{
		return sqrtl(x * x + y * y);
	}
	ld r2()
	{
		return x * x + y * y;
	}
	int q()
	{
		if (x > 0 && y >= 0)
			return 0;
		if (x >= 0)
			return 1;
		if (y <= 0)
			return 2;
		return 3;
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
point operator*(ld k, point a)
{
	return point(a.x * k, a.y * k);
}
point operator*(point a, point b)
{
	return point(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
ld cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
ld dot(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}
const ld eps = 1e-6;
point X(point a, point b, point c, point d)
{
	//a+xb=c+yd
	//xbd=cd-ad
	assert(abs(cross(b, d)) > eps);
	ld x = cross(c - a, d) / cross(b, d);
	return a + x * b;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	point A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i].x >> A[i].y;
	ld ans = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < j; k++)
			{
				if (abs(cross(A[i] - A[j], A[j] - A[k])) < 0.5)
					continue;
				point o = X(0.5 * (A[i] + A[j]), (A[j] - A[i]) * point(0, 1),
				            0.5 * (A[j] + A[k]), (A[j] - A[k]) * point(0, 1));
				ld r2 = (o - A[i]).r2();
				bool ok = true;
				vector<point>B[4];
				for (int l = 0; l < n; l++)
				{
					point v = A[l] - o;
					ld r2l = v.r2();
					if (r2l < r2 - eps)
					{
						ok = false;
						break;
					}
					if (r2l < r2 + eps)
					{
						int id = v.q();
						if (B[id].empty())
							B[id] = {v};
						else if (B[id].size() == 1)
						{
							B[id].push_back(v);
							if (cross(B[id][0], B[id][1]) < 0)
								swap(B[id][0], B[id][1]);
						}
						else
						{
							if (cross(v, B[id][0]) > 0)
								B[id][0] = v;
							else if (cross(B[id][1], v) > 0)
								B[id][1] = v;
						}
					}
				}
				if (ok)
				{
					bool uzd = false;
					vector<point>A;
					for (int i = 0; i < 4; i++)
						for (point a : B[i])
							A.push_back(a);
					for (int i = 0; i < (int)A.size(); i++)
					{
						bool ok = true;
						for (int j = 0; j < (int)A.size(); j++)
						{
							ok &= cross(A[i], A[j]) >= -eps;
						}
						if (ok)
						{
							uzd = true;
							break;
						}
					}
					if (!uzd)
						ans = max(ans, r2);
				}
			}
		}
	}

	if (ans < 0)
		cout << -1 << "\n";
	else
		cout << fixed << setprecision(10) << sqrtl(ans) << "\n";
	return 0;
}