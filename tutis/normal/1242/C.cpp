/*input
2
2 1 2
10 0 1000000000 999999999 999999998 999999997 999999996 999999995 999999994 999999993 589934621
*/
#include <bits/stdc++.h>
using ld = long double;
using ll = long long;
using namespace std;
bool ok[1 << 15];
int val[1 << 15][15];
int main()
{
	int k;
	cin >> k;
	vector<int>A[k];
	ll avg = 0;
	ll S[k];
	map<ll, int>M;
	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;
		A[i] = vector<int>(n);
		S[i] = 0;
		for (int &v : A[i])
		{
			cin >> v;
			S[i] += v;
			M[v] = i;
		}
		avg += S[i];
	}
	if (avg % k != 0)
	{
		cout << "No\n";
		return 0;
	}
	avg /= k;
	ll ga[k];
	for (int i = 0; i < k; i++)
	{
		for (int x : A[i])
		{
			int msk = (1 << i);
			ll gaus = avg + x - S[i];
			ga[i] = gaus;
			bool ger = true;
			while (true)
			{
				if (M.count(gaus) == 0)
				{
					ger = false;
					break;
				}
				int j = M[gaus];
				gaus = avg + gaus - S[j];
				if ((msk & (1 << j)) == 0)
				{
					ga[j] = gaus;
					msk ^= (1 << j);
				}
				else
				{
					ger &= ga[j] == gaus;
					ger &= j == i;
					break;
				}
			}
			if (ger && (!ok[msk]))
			{
				ok[msk] = true;
				for (int i = 0; i < k; i++)
					val[msk][i] = ga[i];
			}
		}
	}
	for (int msk = 1; msk < (1 << k); msk++)
	{
		for (int sub = (msk - 1)&msk; sub > 0 && (!ok[msk]); sub = (sub - 1)&msk)
		{
			if (ok[sub] && ok[msk ^ sub])
			{
				ok[msk] = true;
				for (int i = 0; i < k; i++)
				{
					if (((1 << i)&sub) != 0)
						val[msk][i] = val[sub][i];
					else
						val[msk][i] = val[msk ^ sub][i];
				}
			}
		}
	}
	int msk = (1 << k) - 1;
	if (ok[msk])
	{
		cout << "Yes\n";
		int c[k], p[k];
		for (int i = 0; i < k; i++)
		{
			int g = val[msk][i];
			int j = M[g];
			c[j] = g;
			p[j] = i;
		}
		for (int i = 0; i < k; i++)
			cout << c[i] << " " << p[i] + 1 << "\n";
	}
	else
	{
		cout << "No\n";
	}
}