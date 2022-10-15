/*input
3
5 4
3 2
6 1

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int v1[2 * 303030 + 1];
int v2[2 * 303030 + 1];
int a[303030 + 1];
int b[303030 + 1];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	for (int i = 1; i <= n; i++)
	{
		if (a[i] < b[i])
		{
			v1[b[i]] = i;
		}
		else
		{
			v2[b[i]] = i;
		}
	}
	vector<int>g1;
	vector<int>g2;
	for (int i = 2 * n; i >= 1; i--)
	{
		if (v1[i] != 0)
			g1.push_back(v1[i]);
	}
	for (int i = 1; i <= 2 * n; i++)
	{
		if (v2[i] != 0)
			g2.push_back(v2[i]);
	}
	if (g2.size() >= g1.size())
		g1 = g2;
	cout << g1.size() << "\n";
	for (int i : g1)
		cout << i << " ";
	cout << "\n";
}