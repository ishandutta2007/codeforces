/*input
6
YES
NO
NO
YES
NO
*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937 rng(0);
const ll mod = 1e9 + 7;
ll power(ll x, ll y)
{
	y %= mod - 1;
	x %= mod;
	if (x < 0)
		x += mod;
	if (y < 0)
		y += mod - 1;
	ll r = 1;
	while (y)
	{
		if (y % 2)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
struct intervalset
{
	int sz = 0;
	vector<pair<int, int>>S;//sorted, disjoint
	intervalset()
	{

	}
	intervalset(int N)
	{
		sz = N;
		S.push_back({1, N});
	}
	void append(pair<int, int> v)
	{
		sz += v.second - v.first + 1;
		if (S.empty())
			S.push_back(v);
		else {
			if (v.first > S.back().second)
			{
				if (v.first == S.back().second + 1)
					S.back().second = v.second;
				else
					S.push_back(v);
			}
			else
			{
				assert(v.first >= S.back().first);
				if (v.second > S.back().second) {
					sz -= S.back().second - v.first + 1;
					S.back().second = v.second;
				}
			}
		}
	}
	pair<intervalset, intervalset> split(int k)
	{	//k,sz-k
		intervalset A;
		intervalset B;
		for (pair<int, int>i : S)
		{
			if (i.second - i.first + 1 <= k)
			{
				A.append(i);
				k -= i.second - i.first + 1;
			}
			else if (k <= 0)
			{
				B.append(i);
			}
			else
			{
				A.append({i.first, i.first + k - 1});
				B.append({i.first + k, i.second});
				k = 0;
			}
		}
		return {A, B};
	}
	int kth(int k)
	{
		for (pair<int, int>i : S)
		{
			if (i.second - i.first + 1 < k)
			{
				k -= i.second - i.first + 1;
			}
			else
			{
				return i.first + (k - 1);
			}
		}
		assert(false);
		return 0;
	}
	int kelintas(int x)
	{
		int r = 0;
		for (pair<int, int>i : S)
		{
			if (i.second < x)
				r += (i.second - i.first + 1);
			else if (x < i.first)
				return 0;
			else
				return r + (x - i.first + 1);
		}
		return 0;
	}
	intervalset(const intervalset &A, const intervalset &B)
	{
		const vector<pair<int, int>>&a = A.S;
		const vector<pair<int, int>>&b = B.S;
		int i = 0;
		int j = 0;
		while (i < (int)a.size() && j < (int)b.size())
		{
			if (a[i].first < b[j].first)
				append(a[i++]);
			else
				append(b[j++]);
		}
		while (i < (int)a.size())
			append(a[i++]);
		while (j < (int)b.size())
			append(b[j++]);
	}
};
const int mxsum = 100;
pair<int, pair<int, int>> K[mxsum][mxsum];
bool prec = false;
pair<int, int> getbest(int A, int B)
{
	if (A + B < mxsum)
	{
		if (prec == false)
		{
			prec = true;
			for (int sum = 0; sum < mxsum; sum++)
				for (int a = 0; a <= sum; a++)
				{
					int b = sum - a;
					K[a][b] = {1000, {0, 0}};
				}
			for (int sum = 0; sum < mxsum; sum++)
			{
				if (sum <= 2)
				{
					for (int a = 0; a <= sum; a++) {
						int b = sum - a;
						K[a][b] = {0, {0, 0}};
					}
				}
				else {
					bool rep = true;
					while (rep)
					{
						rep = false;
						for (int a = 0; a <= sum; a++)
						{
							int b = sum - a;

							for (int a0 = 0; a0 <= a; a0++)
							{
								for (int b0 = 0; b0 <= b; b0++)
								{
									int a1 = a - a0;
									int b1 = b - b0;

									int a_ = a0 + b0;
									int b_ = a1;

									int a__ = a1 + b1;
									int b__ = a0;
									int g = 1 + max(K[a_][b_].first, K[a__][b__].first);
									if (K[a][b].first > g)
									{
										K[a][b] = {g, {a0, b0}};
										rep = true;
									}
								}
							}
						}
					}
				}
			}
		}
		return K[A][B].second;
	}
	else
	{
		return {A / 2, B / 2};
	}
}
pair<int, int> decode(int N)
{
	intervalset A(N);
	intervalset B;
	mt19937 rng(0);
	while (A.sz + B.sz > 2)
	{
		pair<int, int>c = getbest(A.sz, B.sz);
		int a0 = c.first;
		int b0 = c.second;
		pair<intervalset, intervalset>A_ = A.split(a0);
		pair<intervalset, intervalset>B_ = B.split(b0);
		intervalset x(A_.first, B_.first);
		cout << "? " << x.sz;
		for (auto i : x.S)
			for (int v = i.first; v <= i.second; v++)
				cout << " " << v;
		cout << endl;
		string s;
		cin >> s;
		if (s == "YES")
		{
			A = intervalset(A_.first, B_.first);
			B = A_.second;
		}
		else
		{
			A = intervalset(A_.second, B_.second);
			B = A_.first;
		}
	}
	if (A.sz == 0)
		return {B.S[0].first, B.S.back().second};
	if (B.sz == 0)
		return {A.S[0].first, A.S.back().second};
	return {A.S[0].first, B.S[0].first};
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	pair<int, int>a = decode(n);
	cout << "! " << a.first << endl;
	string s;
	cin >> s;
	if (s[1] == ')')
		return 0;
	cout << "! " << a.second << endl;
	cin >> s;
	return 0;
}