/*input
3
1 1 2 2 3 3
0 1 1 0 2 2
9 3 7 9 9 8
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
const ld eps = 1e-7;
point X(point a, point b, point c, point d)
{
	b = b - a;
	d = d - c;
	//a+xb=c+yd
	//xbd=cd-ad
	assert(abs(cross(b, d)) > eps);
	ld x = cross(c - a, d) / cross(b, d);
	return a + x * b;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		point A[3];
		for (int i = 0; i < 3; i++)
		{
			int a, b;
			cin >> a >> b;
			A[i].x = a;
			A[i].y = b;
		}
		if (abs(cross(A[0] - A[1], A[1] - A[2])) < 0.5)
		{
			cout << "NO\n\n";
			continue;
		}
		for (int t = 0; t < 3; t++)
		{
			swap(A[0], A[1]);
			swap(A[1], A[2]);

			point a = A[0];
			point b = A[1];
			point c = A[2];
			point d = a + c - b;
			point a_ = 0.5 * (a + b);
			point c_ = 0.5 * (b + c);
			point o = X(a_, a_ + (b - a) * point(0, 1), c_, c_ + (c - b) * point(0, 1));
			point b_ = 2.0 * b - o;
			if (abs(cross(c_ - o, o - a_)) > eps)
			{
				point bc = X(o, c_, b_, b_ + o - a_);
				point ab = 2.0 * b - bc;
				point ad = 2 * a - ab;
				point cd = 2 * c - bc;
				if ((cd + ad - 2.0 * d).r() < eps)
				{
					point A[4] = {ad, cd, bc, ab};
					bool ger = true;
					for (int i = 0; i < 4; i++)
					{
						int j = (i + 1) % 4;
						int k = (j + 1) % 4;
						int l = (k + 1) % 4;
						ger &= abs(cross(A[i] - A[j], A[j] - A[k])) > eps;
						ger &= (cross(A[i] - A[j], A[j] - A[k]) > 0) ^ (cross(A[j] - A[k], A[l] - A[k]) > 0);
					}
					if (ger)
					{
						cout << "YES\n";
						for (int t = 0; t < 4; t++)
							cout << fixed << setprecision(20) << A[t].x << " " << A[t].y << " ";
						cout << "\n";
						goto ok;
					}
				}
			}
		}
		cout << "NO\n\n";
ok:;
	}
	return 0;
}