/*input
6 0 6 6 0 6 0 0
7 4 4 7 7 10 10 7
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int A[205][205];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	pair<int , int> a[4];
	pair<int , int> b[4];
	for (int t = 0; t < 4; t++)
	{
		cin >> a[t].first >> a[t].second;
		a[t].first += 100;
		a[t].second += 100;
	}
	for (int t = 0; t < 4; t++)
	{
		cin >> b[t].first >> b[t].second;
		b[t].first += 100;
		b[t].second += 100;
	}
	sort(a, a + 4);
	sort(b, b + 4);
	for (int x = 0; x <= 200; x++)
		for (int y = 0; y <= 200; y++)
			A[x][y] = 0;
	for (int x = a[0].first; x <= a[3].first; x++)
	{
		for (int y = a[0].second; y <= a[3].second; y++)
		{
			A[x][y]++;
		}
	}
	for (int x = b[0].first; x <= b[3].first; x++)
	{
		int dy = 0;
		dy = min(abs(x - b[0].first), abs(x - b[3].first));
		for (int y = b[0].second - dy; y <= b[0].second + dy; y++)
		{
			if (A[x][y] >= 1)
			{
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
}