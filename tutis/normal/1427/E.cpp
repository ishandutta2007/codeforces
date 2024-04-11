/*input
3
*/
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
vector<pair<ull, pair<char, ull>>>ans;
set<ull>jau;
void Sum(ull a, ull b)
{
	if (jau.count(a + b) == 0)
	{
		jau.insert(a + b);
		ans.push_back({a, {'+', b}});
	}
}
void Xor(ull a, ull b)
{
	if (jau.count(a ^ b) == 0)
	{
		jau.insert(a ^ b);
		ans.push_back({a, {'^', b}});
	}
}
void fix(vector<ull>&a)
{
	vector<ull>x;
	for (ull i : a)
	{
		for (ull j : x)
		{
			if ((i ^ j) < i)
			{
				Xor(i, j);
				i = i ^ j;
			}
		}
		if (i != 0)
		{
			x.push_back(i);
			sort(x.begin(), x.end(), greater<ull>());
		}
	}
	a = x;
}
vector<ull>a;
bool can(ull x)
{
	for (ull i : a)
	{
		if ((x ^ i) < x)
		{
			x = x ^ i;
		}
	}
	return x == 0;
}
int main()
{
	ull x;
	cin >> x;
	Xor(x, x);
	a.push_back(x);
	fix(a);
	while (jau.count(1) == 0)
	{
		for (ull i : a)
		{
			for (ull j : a)
			{
				if (can(i + j) == false && i + j <= 2e18)
				{
					Sum(i, j);
					a.push_back(i + j);
					fix(a);
					goto AAA;
				}
			}
		}
AAA:;
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
}