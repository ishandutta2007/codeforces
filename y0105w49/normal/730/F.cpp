#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, b;
	cin >> n >> b;
	vector<int> cost(n), lim(n), bonus(n);
	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];
		lim[i] = cost[i] / 2;
	}

	auto valid = [&]() {
		int x = b;
		for (int i = 0; i < n; i++)
		{
			if (bonus[i] > x)
			{
				return false;
			}
			if (bonus[i] > lim[i])
			{
				return false;
			}
			x -= bonus[i];
			x += cost[i] / 10;
		}
		return true;
	};
	
	int arr[] = {1, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	for (int z = 0; z < sizeof(arr) / sizeof(arr[0]); z++)
	{
		int amount = arr[z];
		for (int i = n-1; i >= 0; i--)
		{
			while (true)
			{
				if (z == 0 && cost[i] % 10 == 0)
				{
					break;
				}
				bonus[i] += amount;
				cost[i] -= amount;
				if (!valid())
				{
					bonus[i] -= amount;
					cost[i] += amount;
					break;
				}
			}
		}
	}
	
	int tot = 0;
	for (int i = 0; i < n; i++)
	{
		tot += cost[i];
	}
	cout << tot << endl;
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			cout << ' ';
		cout << bonus[i];
	}
	cout << endl;
}