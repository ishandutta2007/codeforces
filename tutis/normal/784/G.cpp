/*input
2+3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	string a;
	cin >> a;
	a = "+" + a + "+";
	ll ans = 0;
	for (int i = 0; i + 1 < a.size(); i++)
	{
		if (a[i] == '+' || a[i] == '-')
		{
			string A;
			for (int j = i + 1;; j++)
			{
				if (a[j] == '+' || a[j] == '-')
					break;
				A.push_back(a[j]);
			}
			if (a[i] == '+')
				ans += stoi(A);
			else
				ans -= stoi(A);
		}
	}
	int w = 0;
	char c = 0;
	while (c != '0')
	{
		cout << "+";
		c++;
	}
	if (ans == 0)
	{
		cout << '.';
		return 0;
	}
	vector<int>x;
	while (ans > 0)
	{
		x.push_back(ans % 10);
		ans /= 10;
	}
	reverse(x.begin(), x.end());
	for (int a : x)
	{
		while (w > a)
		{
			cout << "-";
			w--;
		}
		while (w < a)
		{
			cout << "+";
			w++;
		}
		cout << ".";
	}
}