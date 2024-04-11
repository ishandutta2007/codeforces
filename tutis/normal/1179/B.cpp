/*input
2 3

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int x = 1;
	int y = 1;
	int x_ = n;
	int y_ = m;
	while (x < x_)
	{
		cout << x << " " << y << '\n';
		cout << x_ << " " << y_ << '\n';
		y++;
		y_--;
		if (y > m)
		{
			y = 1;
			y_ = m;
			x++;
			x_--;
		}
	}
	if (x == x_)
	{
		while (y < y_)
		{
			cout << x << " " << y << '\n';
			cout << x_ << " " << y_ << '\n';
			y++;
			y_--;
		}
		if (y == y_)
			cout << x << " " << y << '\n';
	}
}