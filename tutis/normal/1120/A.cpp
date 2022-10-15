/*input
20 5 4 2
10 8 7 2 5 2 7 5 1 10 7 5 9 9 7 4 3 4 8 2
7 8
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int K[500001];
int R[500001];
int truksta = 0;
void add(int i)
{
	K[i]++;
	if (K[i] == R[i])
		truksta--;
}
void rem(int i)
{
	if (K[i] == R[i])
		truksta++;
	K[i]--;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k, m, s;
	cin >> m >> k >> n >> s;
	int a[m];
	for (int &i : a)
		cin >> i;
	int b[s];
	for (int &i : b)
	{
		cin >> i;
		if (R[i] == 0)
			truksta++;
		R[i]++;
	}
	int l = 0;
	for (int r = 0; r < m; r++)
	{
		add(a[r]);
		while (l < r && (r - l + 1) > k)
		{
			rem(a[l]);
			if (truksta == 0)
				l++;
			else
			{
				add(a[l]);
				break;
			}
		}
		if (truksta == 0)
		{
			int isimam = l % k + (r - l + 1) - k;
			if (m - isimam >= n * k)
			{
				vector<int>ans;
				for (int i = 0; i < (l % k); i++)
				{
					isimam--;
					ans.push_back(i);
				}
				for (int i = l; i <= r && isimam > 0; i++)
				{
					rem(a[i]);
					if (truksta == 0)
					{
						ans.push_back(i);
						isimam--;
					}
					else
						add(a[i]);
				}
				cout << ans.size() << "\n";
				for (int i : ans)
					cout << i + 1 << " ";
				exit(0);
			}
		}
	}
	cout << "-1\n";
}