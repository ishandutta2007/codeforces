/*input
100000 3
43791 91790 34124
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool panaudota[200000 + 1];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n + 100];
	int mx = 0;
	stack<int>X;
	for (int i = 0; i < k; i++)
	{
		cin >> a[i];
		X.push(a[i]);
		while (!X.empty() && X.top() == mx + 1)
		{
			mx = X.top();
			X.pop();
		}
	}
	int j = k;
	while (!X.empty())
	{
		for (int c = X.top() - 1; c > mx; c--)
		{
			a[j++] = c;
			if (j > n + 2)
			{
				cout << "-1\n";
				return 0;
			}
		}
		mx = X.top();
		X.pop();
	}
	for (int c = n; c > mx; c--)
	{
		a[j++] = c;
		if (j > n + 2)
		{
			cout << "-1\n";
			return 0;
		}
	}
	mx = 0;
	for (int i = 0; i < n; i++)
	{
		X.push(a[i]);
		while (!X.empty() && X.top() == mx + 1)
		{
			mx = X.top();
			X.pop();
		}
	}
	if (mx == n)
	{
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
	}
	else
	{
		cout << "-1\n";
	}
}