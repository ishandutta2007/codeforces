/*input
5 3
wxhak
3 3 h x
1 5 x a
1 3 w g
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int ceiling(int a, int b)
{
	if (a % b == 0)
		return a / b;
	return a / b + 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	while (m--)
	{
		int l, r;
		char c1, c2;
		cin >> l >> r >> c1 >> c2;
		for (int i = l - 1; i < r; i++)
		{
			if (s[i] == c1)
				s[i] = c2;
		}
	}
	cout << s << "\n";
}