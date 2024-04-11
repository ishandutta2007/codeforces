/*input
5 5
1 4
5 2
4 3
1 5
5 4

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
template<typename T, size_t N>
void gauss(array<array<T, N>, N> &A, array<T, N> &B)
{
	for (int i = 0; i < N; i++)
	{
		int s = i;
		for (int j = i; j < N; j++)
			if (abs(A[j][i]) > abs(A[s][i]))
				s = j;
		swap(A[i], A[s]);
		swap(B[i], B[s]);
		T c = 1 / A[i][i];
		for (int j = i; j < N; j++)
			A[i][j] *= c;
		B[i] *= c;
		assert(A[i][i] != 0);
		for (int j = i + 1; j < N; j++)
		{
			T c = -A[j][i];
			for (int k = i; k < N; k++)
				A[j][k] += A[i][k] * c;
			B[j] += B[i] * c;
		}
	}
	for (int i = N - 1; i >= 0; i--)
	{
		assert(A[i][i] == 1);
		for (int j = i - 1; j >= 0; j--)
		{
			T c = -A[j][i];
			B[j] += B[i] * c;
			for (int k = i; k < N; k++)
				A[j][k] += c * A[i][k];
		}
	}
}
const int mod = 998244353;
class Z
{
private:
	mutable int x;//-mod < x < mod
public:
	Z()
	{
		x = 0;
	}
	Z(int a)
	{
		x = a;
		if (abs(x) >= mod)
			x %= mod;
	}
	template<typename T>
	Z(T a)
	{
		if (abs(a) >= mod)
			a %= mod;
		x = a;
	}
	Z operator++(int)
	{
		x++;
		if (x == mod)
			x = 0;
		return *this;
	}
	Z operator++()
	{
		x++;
		Z ret = *this;
		if (x == mod)
			x = 0;
		return ret;
	}
	Z operator--(int)
	{
		x--;
		if (x == -mod)
			x = 0;
		return *this;
	}
	Z operator--()
	{
		x--;
		Z ret = *this;
		if (x == -mod)
			x = 0;
		return ret;
	}
	template<typename T>
	Z operator^(T v)const
	{
		v %= mod - 1;
		if (v < 0)
			v += mod - 1;
		ll r = 1;
		for (ll xx = x; v; v /= 2, xx = (xx * xx) % mod)
			if (v % 2 == 1)
				r = (r * xx) % mod;
		return Z(r);
	}
	Z operator!()const
	{
		return (*this) ^ (-1);
	}
	Z operator-()const
	{
		return Z(-x);
	}
	bool operator==(const Z&o)const
	{
		if (x < 0)
			x += mod;
		if (o.x < 0)
			o.x += mod;
		return x == o.x;
	}
	bool operator!=(const Z&o)const
	{
		if (x < 0)
			x += mod;
		if (o.x < 0)
			o.x += mod;
		return x != o.x;
	}
	template<typename T>
	bool operator!=(T v)const
	{
		return (*this) != Z(v);
	}
	void operator*=(const Z&o)
	{
		ll v = 1ll * x * o.x;
		if (abs(v) >= mod)
			v %= mod;
		x = v;
	}
	Z operator*(const Z&o)const
	{
		return Z(1ll * x * o.x);
	}
	Z operator/(const Z&o)const
	{
		return (*this) * (!o);
	}
	template<typename T>
	friend Z operator/(T a, const Z&o)
	{
		return Z(a) * (!o);
	}
	template<typename T>
	friend Z operator*(T a, const Z&o)
	{
		return Z(a) * o;
	}
	template<typename T>
	Z operator+(const Z&b)const
	{
		Z c;
		c.x = x + b.x;
		if (c.x >= mod)
			c.x -= mod;
		if (c.x <= mod)
			c.x += mod;
		return c;
	}
	template<typename T>
	friend Z operator+(T a, const Z&o)
	{
		return Z(a) + o;
	}
	template<typename T>
	Z operator-(const Z&b)const
	{
		Z c;
		c.x = x - b.x;
		if (c.x >= mod)
			c.x -= mod;
		if (c.x <= mod)
			c.x += mod;
		return c;
	}
	template<typename T>
	friend Z operator-(T a, const Z&o)
	{
		return Z(a) - o;
	}
	void operator+=(const Z &o)
	{
		x += o.x;
		if (x >= mod)
			x -= mod;
		if (x <= -mod)
			x += mod;
	}
	void operator-=(const Z &o)
	{
		x -= o.x;
		if (x >= mod)
			x -= mod;
		if (x <= -mod)
			x += mod;
	}
	friend int abs(const Z&o)
	{
		return abs(o.x);
	}
	friend ostream& operator<<(ostream& os, const Z &x)
	{
		if (x.x < 0)
			x.x += mod;
		os << x.x;
		return os;
	}
	friend istream& operator>>(istream& is, Z &x)
	{
		ll v;
		is >> v;
		x = v;
		return is;
	}
};
const int maxG = 512;
array<array<Z, maxG>, maxG>A;
array<Z, maxG>B;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int>d(n + 1, 0);
	vector<int>in[n + 1];
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		d[x]++;
		in[y].push_back(x);
	}
	set<int>V[n + 1];
	queue<int>Q;
	for (int i = 1; i <= n; i++)
		if (d[i] == 0)
			Q.push(i);
	array<Z, maxG>G;
	while (!Q.empty())
	{
		int a = Q.front();
		Q.pop();
		int g = 0;
		while (V[a].count(g))
			g++;
		G[g]++;
		for (int b : in[a])
		{
			d[b]--;
			if (d[b] == 0)
			{
				Q.push(b);
			}
			V[b].insert(g);
		}
	}
	Z n1_ = 1 / Z(n + 1);
	for (int v = 0; v < maxG; v++)
	{
		for (int w = 0; w < maxG; w++)
			A[v][w] = 0;
		A[v][v] = mod - 1;
		for (int w = 0; w < maxG; w++)
		{
			A[v][w] += G[v ^ w] * n1_;
		}
		if (v != 0)
			B[v] = -n1_;
		else
			B[v] = 0;
	}
	gauss(A, B);
	cout << B[0] << "\n";
}