/*input
1 2 3
6
A 0 0 1
A 1 0 0
A 0 1 0
A 1 1 1
R 1
R 2
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct viktor
{
	ll x, y, z;
	viktor()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	viktor(ll x, ll y, ll z): x(x), y(y), z(z)
	{

	}
	int sgn()
	{
		if (x == 0 && y == 0 && z == 0)
			return 0;
		if (x < 0 || (x == 0 && (y < 0 || (y == 0 && z < 0))))
			return -1;
		return 1;
	}
	void normalize()
	{
		ll g = 0;
		if (x != 0)
			g = __gcd(g, abs(x));
		if (y != 0)
			g = __gcd(g, abs(y));
		if (z != 0)
			g = __gcd(g, abs(z));
		assert(g != 0);
		x /= g;
		y /= g;
		z /= g;
		if (x < 0 || (x == 0 && (y < 0 || (y == 0 && z < 0))))
		{
			x *= -1;
			y *= -1;
			z *= -1;
		}
	}
	bool operator==(const viktor &o)
	{
		return (x == o.x && y == o.y && z == o.z);
	}
	bool operator<(const viktor &o)const
	{
		if (x != o.x)
			return x < o.x;
		if (y != o.y)
			return y < o.y;
		return z < o.z;
	}
};
viktor cross(viktor a, viktor b)
{
	viktor c;
	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	c.normalize();
	return c;
}
ll V(viktor a, viktor b, viktor c)
{
	ll s = c.x * (a.y * b.z - a.z * b.y) +
	       c.y * (a.z * b.x - a.x * b.z) +
	       c.z * (a.x * b.y - a.y * b.x);
	if (s < 0)
		return -1;
	if (s == 0)
		return 0;
	return 1;
}
int S(viktor a, viktor b)
{
	viktor c;
	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return c.sgn();
}
viktor v;
struct oper
{
	bool operator()(const viktor &x, const viktor &y)const
	{
		int s = V(x, y, v);
		if (s == 0)
			return x < y;
		else
			return s > 0;
	}
};
viktor a;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> v.x >> v.y >> v.z;
	v.normalize();
	ll n;
	cin >> n;
	viktor A[n + 1];
	int id = 0;
	int kiekv = 0;
	int kiek2 = 0;
	map<viktor, pair<int, int>>M2;
	bool turiu = false;
	multiset<viktor, oper>PL, MI, NU;
	while (n--)
	{
		{
			char c;
			cin >> c;
			if (c == 'A')
			{
				id++;
				viktor w;
				cin >> w.x >> w.y >> w.z;
				w.normalize();
				A[id] = w;
				if (v == w)
					kiekv++;
				else
				{
					if (!turiu)
					{
						a = w;
						turiu = true;
					}
					viktor vw = cross(v, w);
					if (M2.count(vw) == 0)
						M2[vw] = {0, 0};
					if (M2[vw].first > 0 && M2[vw].second > 0)
						kiek2--;
					if (S(v, w) > 0)
						M2[vw].first++;
					else
						M2[vw].second++;
					if (M2[vw].first > 0 && M2[vw].second > 0)
						kiek2++;
					int s = V(a, v, w);
					if (s == 0)
						NU.insert(w);
					else if (s == 1)
						PL.insert(w);
					else
						MI.insert(w);
				}
			}
			else
			{
				int r;
				cin >> r;
				if (A[r] == v)
					kiekv--;
				else
				{
					viktor vw = cross(v, A[r]);
					if (M2[vw].first > 0 && M2[vw].second > 0)
						kiek2--;
					if (S(v, A[r]) > 0)
						M2[vw].first--;
					else
						M2[vw].second--;
					if (M2[vw].first > 0 && M2[vw].second > 0)
						kiek2++;
					int s = V(a, v, A[r]);
					if (s == 0)
						NU.erase(NU.find(A[r]));
					else if (s == 1)
						PL.erase(PL.find(A[r]));
					else
						MI.erase(MI.find(A[r]));
				}
			}
		}
		if (kiekv > 0)
		{
			cout << "1\n";
		}
		else if (kiek2 > 0)
		{
			cout << "2\n";
		}
		else
		{
			vector<viktor>X;
			if (!MI.empty())
			{
				X.push_back(*MI.begin());
				X.push_back(*(--MI.end()));
			}
			if (!NU.empty())
			{
				X.push_back(*NU.begin());
				X.push_back(*(--NU.end()));
			}
			if (!PL.empty())
			{
				X.push_back(*PL.begin());
				X.push_back(*(--PL.end()));
			}
			bool ok = false;
			for (int i = 0; i < X.size(); i++)
			{
				for (int j = 0; j < i; j++)
				{
					for (int k = 0; k < j; k++)
					{
						ll s1 = V(X[j], X[k], v);
						ll s2 = V(X[k], X[i], v);
						ll s3 = V(X[i], X[j], v);
						if (s1 == s2 && s2 == s3 && s1 != 0)
						{
							ok = true;
							break;
						}
					}
					if (ok)
						break;
				}
				if (ok)
					break;
			}
			if (ok)
				cout << "3\n";
			else
				cout << "0\n";
		}
	}

	return 0;
}