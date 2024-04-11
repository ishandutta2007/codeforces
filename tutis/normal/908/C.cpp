/***
6 2
5 5 6 8 3 12
***/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int n, r;
ld h(int x, pair<int, ld>a)
{
	int x1 = x;
	int x2 = a.first;
	ld y = a.second;
	int d = abs(x2 - x1);
	if (d > r * 2)
		return 0;
	return y + sqrtl((2 * r) * (2 * r) - d * d);
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> r;
	vector<pair<int, ld>>A;
	while (n--)
	{
		int x;
		cin >> x;
		ld y = r;
		for (pair<int, ld>a : A)
		{
			y = max(y, h(x, a));
		}
		cout << setprecision(15) << y << " ";
		A.push_back(make_pair(x, y));
	}
}