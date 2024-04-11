/*input
1
2750131 199999

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
vector<int>ps;
int maziaus[3000000];
int K[3000000];
int main()
{
	for (int i = 2; i < 3000000; i++)
	{
		if (maziaus[i] == 0)
		{
			ps.push_back(i);
			for (int j = i; j < 3000000; j += i)
			{
				if (maziaus[j] == 0)
					maziaus[j] = i;
			}
		}
	}
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>bb;
	for (int i = 0; i < 2 * n; i++)
	{
		int x;
		cin >> x;
		K[x]++;
		bb.push_back(x);
	}
	sort(bb.begin(), bb.end(), greater<int>());
	for (int i : bb)
	{
		if (i <= 200000)
		{
			if (K[i] > 0 && K[i / maziaus[i]] > 0)
			{
				cout << i << " ";
				K[i]--;
				K[i / maziaus[i]]--;
				continue;
			}
		}
	}
	for (int i : bb)
	{
		if (i <= 200000)
		{
			if (K[i] > 0 && K[ps[i - 1]] > 0)
			{
				cout << i << " ";
				K[i]--;
				K[ps[i - 1]]--;
				continue;
			}
		}
	}
}