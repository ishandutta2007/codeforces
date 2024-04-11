#include <bits/stdc++.h>
using namespace std;

const int p = 1e9 + 7;
int n;
vector <int> Ve;
set <int> Buy, Sell;
long long ans = 1;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		if (str == "ADD")
		{
			int x;
			scanf("%d", &x);
			Ve.push_back(x);
		}
		else
		{
			sort(Ve.begin(), Ve.end());
			int x;
			scanf("%d", &x);
			int pos = lower_bound(Ve.begin(), Ve.end(), x) - Ve.begin();
			if (pos < (int) Ve.size() && Ve[pos] == x)
			{
				int tmp = 2;
				if (Buy.size() && *Buy.rbegin() > x) tmp--;
				if (Sell.size() && *Sell.begin() < x) tmp--;
				(ans *= tmp) %= p;
				for (int i = 0; i < pos; i++)
					Buy.insert(Ve[i]);
				for (int i = pos + 1; i < (int) Ve.size(); i++)
					Sell.insert(Ve[i]);
			}
			else
			{
				if (Buy.size() && *Buy.rbegin() == x) Buy.erase(*Buy.rbegin());
				else if (Sell.size() && *Sell.begin() == x) Sell.erase(Sell.begin());
				else return puts("0"), 0;
				for (int i = 0; i < pos; i++)
					Buy.insert(Ve[i]);
				for (int i = pos; i < (int) Ve.size(); i++)
					Sell.insert(Ve[i]);
			}
			if (Buy.size() && Sell.size() && *Buy.rbegin() > *Sell.begin())
				return puts("0"), 0;
			Ve.clear();
		}
	}
	if (Ve.size())
	{
		sort(Ve.begin(), Ve.end());
		long long tmp = 0;
		for (int i = -1; i < (int) Ve.size(); i++)
		{
			if (i >= 0 && Sell.size() && Ve[i] > *Sell.begin()) continue;
			if (i + 1 < (int) Ve.size() && Buy.size() && Ve[i + 1] < *Buy.rbegin()) continue;
			tmp++;
		}
		(ans *= tmp) %= p;
	}
	printf("%lld", ans);
	return 0;
}