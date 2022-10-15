/*input
5
1 1
1 2
2 1 1 3
2 1 1 2
2 1 1 1

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
set<int>mult[100001];
vector<int>divs[100001];
int main()
{
	for (int i = 1; i <= 100000; i++)
		for (int j = i; j <= 100000; j += i)
			divs[j].push_back(i);
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int a;
			cin >> a;
			if (mult[a].count(a))
				continue;
			for (int b : divs[a])
				mult[b].insert(a);
		}
		if (t == 2)
		{
			int x, k, s;
			cin >> x >> k >> s;
			int hi = s - x;
			int lo = 1;
			if (x % k != 0 || lo > hi)
			{
				cout << "-1\n";
				continue;
			}
			int a = 0;
			for (int t = 16; t >= 0; t--)
			{
				if ((x & (1 << t)) == 0)
				{
					lo = a + (1 << t);
					hi = min(s - x, a + (1 << (t + 1)) - 1);
				}
				else
				{
					lo = max(1, a);
					hi = min(s - x, a + (1 << (t)) - 1);
				}
				auto it = mult[k].lower_bound(lo);
				bool radau = false;
				if (it != mult[k].end() && (*it) <= hi)
					radau = true;
				if ((x & (1 << t)) == 0)
				{
					if (radau)
						a += (1 << t);
				}
				else
				{
					if (!radau)
						a += (1 << t);
				}
			}
			if (mult[a].count(a) && __gcd(x, a) % k == 0 && x + a <= s)
				cout << a << "\n";
			else
				cout << "-1\n";
		}
	}

}