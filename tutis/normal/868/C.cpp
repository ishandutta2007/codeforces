/*input
3 2
1 0
1 1
0 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	clock_t pradzia = clock();
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	bool zino[n][k];
	vector<int>B;
	map<int, int>C;
	for (int i = 0; i < n; i++)
	{
		int kiek = 0;
		int w = 1;
		int sum = 0;
		for (int j = 0; j < k; j++)
		{
			cin >> zino[i][j];
			kiek += zino[i][j];
			w *= 2;
			sum += w * zino[i][j];
		}
		if (kiek != k)
		{
			B.push_back(i);
			C[sum] = i;
		}
	}
	vector<int>D;
	for (pair<int, int>x : C)
		D.push_back(x.second);
	if (B.empty())
	{
		cout << "NO\n";
		return 0;
	}
	while (double(clock() - pradzia) / CLOCKS_PER_SEC <= 1.8)
	{
		{
			set<int>pasirinko;
			int x = rand() % 20 + 1;
			while (x--)
			{
				pasirinko.insert(B[rand() % B.size()]);
			}
			bool ok = true;
			for (int i = 0; i < k; i++)
			{
				int kiek = 0;
				for (int a : pasirinko)
					kiek += zino[a][i];
				if (kiek * 2 > pasirinko.size())
					ok = false;
			}
			if (ok)
			{
				cout << "YES\n";
				return 0;
			}
		}
		{
			set<int>pasirinko;
			int x = rand() % 20 + 1;
			while (x--)
			{
				pasirinko.insert(D[rand() % D.size()]);
			}
			bool ok = true;
			for (int i = 0; i < k; i++)
			{
				int kiek = 0;
				for (int a : pasirinko)
					kiek += zino[a][i];
				if (kiek * 2 > pasirinko.size())
					ok = false;
			}
			if (ok)
			{
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
}