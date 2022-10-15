/***
4
1 2
2 3
2 3
1 2
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	pair<int, int>a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a, a + n, [](pair<int, int>a, pair<int, int>b) {if (a.first != b.first)return a.first < b.first; return a.second < b.second;} );
	int nuo1 = -1;
	int nuo2 = -1;
	for (int i = 0; i < n; i++)
	{
		if (nuo2 > nuo1)
		{
			if (a[i].first >= nuo2)
			{
				nuo2 = a[i].second + 1;
			}
			else if (a[i].first >= nuo1)
			{
				nuo1 = a[i].second + 1;
			}
			else
			{
				cout << "NO";
				return 0;
			}
		}
		else
		{
			if (a[i].first >= nuo1)
			{
				nuo1 = a[i].second + 1;
			}
			else if (a[i].first >= nuo2)
			{
				nuo2 = a[i].second + 1;
			}
			else
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}