/*input
4 10
1 5 2 1 1 1 2 5 7 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	int n, m;
	cin >> n >> m;
	int kiek[101];
	fill_n(kiek, 101, 0);
	if (m < n)
	{
		cout << "0\n";
		return 0;
	}
	while (m--)
	{
		int a;
		cin >> a;
		kiek[a]++;
	}
	int lo = 1;
	int hi = 1000;
	while (lo < hi)
	{
		int m = (lo + hi + 1) / 2;
		int X = 0;
		for (int i = 0; i <= 100; i++)
			X += kiek[i] / m;
		if (X >= n)
			lo = m;
		else
			hi = m - 1;
	}
	cout << lo << "\n";
}