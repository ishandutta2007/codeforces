/*input
6
1 1 1 4 4 4

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int &i : a)
		cin >> i;
	sort(a, a + n);
	set<int>yra;
	for (int i : a)
	{
		if (i > 1 && yra.count(i - 1) == 0)
		{
			yra.insert(i - 1);
			continue;
		}
		if (yra.count(i) == 0)
		{
			yra.insert(i);
			continue;
		}
		if (yra.count(i + 1) == 0)
		{
			yra.insert(i + 1);
			continue;
		}
	}
	cout << yra.size() << "\n";
}