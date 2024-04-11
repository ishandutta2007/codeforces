/*input
8
1 2 3 4 7 8 8 8
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	map<int, int>k;
	for (int &i : a)
	{
		cin >> i;
		k[i]++;
	}
	string ans(n, 'A');
	int c = 'A';
	int k1 = 0;
	int k2 = 0;
	int t = 0;
	for (int &i : a)
	{
		if (k[i] == 1)
		{
			if (c == 'A')
				c = 'B';
			else
				c = 'A';
			if (c == 'A')
				k1++;
			else
				k2++;
			ans[t] = c;
		}
		t++;
	}
	t = 0;
	for (int &i : a)
	{
		if (k[i] == 2)
		{
			ans[t] = 'A';
		}
		t++;
	}
	map<int, char>X;
	t = 0;
	for (int &i : a)
	{
		if (k[i] <= 2)
		{
			t++;
			continue;
		}
		if (X.count(i))
		{
			ans[t] = X[i];
			t++;
			continue;
		}
		if (k1 > k2)
		{
			ans[t] = 'B';
			k2++;
			X[i] = 'A';
		}
		if (k1 < k2)
		{
			ans[t] = 'A';
			k1++;
			X[i] = 'B';
		}

		t++;
	}
	if (k1 == k2)
	{
		cout << "YES\n";
		cout << ans << "\n";
	}
	else
		cout << "NO\n";



}