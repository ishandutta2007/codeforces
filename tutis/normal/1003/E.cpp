/*input
10 9 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, d, k;
	cin >> n >> d >> k;
	if (k == 1)
	{
		if (n <= 2)
		{
			if (n == 1 && d == 0)
			{
				cout << "YES\n";
				return 0;
			}
			if (n == 2 && d == 1)
			{
				cout << "YES\n";
				cout << "1 2\n";
				return 0;
			}
		}
		cout << "NO\n";
		return 0;
	}
	if (d + 1 > n)
	{
		cout << "NO\n";
		return 0;
	}
	int kitas = d + 1;
	vector<pair<int, int>>A;
	for (int i = 2; i <= (d + 1); i++)
	{
		A.push_back({i - 1, i});
	}
	function<void(int, int, int)>medis;
	medis = [&](int i, int d, int kiek)->void
	{
		if (d == 0)
		{
			return;
		}
		while (A.size() < n - 1 && kiek > 0)
		{
			kiek--;
			kitas++;
			A.push_back({i, kitas});
			medis(kitas, d - 1, k - 1);
		}
	};
	for (int i = 2; i <= d; i++)
	{
		int gylis = min(i - 1, d - i + 1);
		medis(i, gylis, k - 2);
	}
	if (A.size() == n - 1)
	{
		cout << "YES\n";
		for (pair<int, int>a : A)
			cout << a.first << " " << a.second << "\n";
	}
	else
	{
		cout << "NO\n";
	}

}