/*input
4
0 0 2 1
1 2 3 3
2 0 3 2
0 1 1 3

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct rect
{
	int a, b, c, d;
};
mt19937 gen(1256);
bool ok(vector<rect>&a)
{
	if (a.size() <= 1)
		return true;
	shuffle(a.begin(), a.end(), gen);
	for (rect i : a)
	{
		{
			vector<rect>l, r;
			for (rect j : a)
			{
				if (j.a >= i.b)
					r.push_back(j);
				else if (j.b <= i.b)
					l.push_back(j);
				else break;
			}
			if (l.size() + r.size() == a.size() && r.size() > 0 && l.size() > 0)
			{
				return (ok(l)&ok(r));
			}
		}
		{
			vector<rect>l, r;
			for (rect j : a)
			{
				if (j.c >= i.d)
					r.push_back(j);
				else if (j.d <= i.d)
					l.push_back(j);
				else break;
			}
			if (l.size() + r.size() == a.size() && r.size() > 0 && l.size() > 0)
			{
				return (ok(l)&ok(r));
			}
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<rect>a(n);
	for (auto &i : a)
		cin >> i.a >> i.c >> i.b >> i.d;
	if (ok(a))
		cout << "YES\n";
	else
		cout << "NO\n";
}