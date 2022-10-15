/*input
6 2
0 1 1 0 0 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, r;
	cin >> n >> r;
	vector<int>sil;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
			sil.push_back(i);
	}
	int l = -1;
	int x = 0;
	for (int i = 0; i < sil.size(); i++)
	{
		if (l + 1 < sil[i] - r + 1)
			continue;
		if (l >= n - 1)
			continue;
		if (i + 1 < sil.size() && l + 1 >= sil[i + 1] - r + 1)
			continue;
		x++;
		l = sil[i] + r - 1;
	}
	if (l < n - 1)
	{
		cout << "-1\n";
	}
	else
	{
		cout << x << "\n";
	}
}