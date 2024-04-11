/*input
9 12
aaabccccc
4 a
4 b
2 b
5 a
1 b
6 b
5 c
2 a
1 a
5 a
6 b
7 b

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
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(0);
template<typename T>
void sort_unique(T &x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
//const ll mod = 998244353;
const ll mod = 1000000007;
ll power(ll a, ll b)
{
	if (abs(a) >= mod)
		a %= mod;
	if (abs(b) >= mod - 1)
		b %= (mod - 1);
	if (a < 0)
		a += mod;
	if (b < 0)
		b += mod - 1;
	ll r = 1;
	if (b % 2 == 1)
		r = a;
	b /= 2;
	while (b)
	{
		a = (a * a) % mod;
		if (b % 2 == 1)
			r = (r * a) % mod;
		b /= 2;
	}
	return r;
}
string s;
struct ST
{
	int l, r;
	int X, Y, Z, XY, YZ, XYZ;
	ST *left, *right;
	ST(int l, int r): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2);
			right = new ST((l + r) / 2 + 1, r);
			merge();
		}
		else
			calc();
	}
	void merge()
	{
		X = left->X + right->X;
		Y = left->Y + right->Y;
		Z = left->Z + right->Z;
		XY = min(left->XY + right->Y, left->X + right->XY);
		YZ = min(left->YZ + right->Z, left->Y + right->YZ);
		XYZ = min({left->XY + right->YZ, left->XYZ + right->Z, left->X + right->XYZ});
		// for (int i = l; i <= r; i++)
		// 	cout << s[i];
		// cout << " " << X << " " << Y << " " << Z << " " << XY << " " << YZ << " " << XYZ << "\n";
	}
	void calc()
	{
		X = Y = Z = 0;
		if (s[l] == 'a')
			X++;
		if (s[l] == 'b')
			Y++;
		if (s[l] == 'c')
			Z++;
		XY = YZ = XYZ = 0;
	}
	void upd(int i)
	{
		if (l < r)
		{
			if (i <= (l + r) / 2)
				left->upd(i);
			else
				right->upd(i);
			merge();
		}
		else
			calc();
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	cin >> s;
	s = " " + s;
	ST med(1, n);
	while (q--)
	{
		int i;
		char c;
		cin >> i >> c;
		s[i] = c;
		med.upd(i);
		cout << med.XYZ << "\n";
	}
}