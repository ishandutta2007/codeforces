#include <bits/stdc++.h>
using namespace std;

string a, b;
int d1[100005], d2[100005];

int main()
{
	cin.sync_with_stdio(false);
	cin >> a >> b;

	for (int i = 0; i < b.size(); i++) d1[i] = d2[i] = -1;

	for (int i = 0, p = 0; i < a.size() && p < b.size(); i++)
	{
		if (a[i] == b[p])
		{
			d1[p] = i;
			p++;
		}
	}

	if (d1[b.size() - 1] != -1)
	{
		cout << b;
		return 0;
	}

	for (int i = a.size() - 1, p = b.size() - 1; i >= 0 && p >= 0; i--)
	{
		if (a[i] == b[p])
		{
			d2[p] = i;
			p--;
		}
	}

	if (d1[0] == -1 && d2[b.size() - 1] == -1)
	{
		cout << "-";
		return 0;
	}

	pair<int, int> ans;
	for (int i = 0;; i++)
	{
		if (d1[i] == -1)
		{
			ans = { i, 0 };
			break;
		}
	}

	for (int i = b.size() - 1;; i--)
	{
		if (d2[i] == -1)
		{
			if (ans.first < b.size() - i - 1) ans = { 0, b.size() - i - 1 };
			break;
		}
	}

	for (int l = 0, r = 0; r < b.size(); r++)
	{
		if (d2[r] == -1) continue;
		while (d1[l+1] != -1 && d1[l+1] < d2[r]) l++;
		if (d1[l] == -1 || d1[l] >= d2[r]) continue;
		if (l + 1 + b.size() - r > ans.first + ans.second)
			ans = { l + 1, b.size() - r };
	}

	cout << b.substr(0, ans.first) << b.substr(b.size() - ans.second);
}