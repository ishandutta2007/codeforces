/*input
3 2 3
***
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, a, b;
	cin >> n >> a >> b;
	int ans = 0;
	char X[n];
	for (int i = 0; i < n; i++)
		cin >> X[i];
	vector<int>vietos;
	int dyd = -1;
	for (int i = 0; i < n; i++)
	{
		if (X[i] == '*' && dyd > 0)
		{
			vietos.push_back(dyd);
			dyd = -1;
		}
		if (X[i] == '.')
		{
			if (dyd < 0)
			{
				dyd = 1;
			}
			else
			{
				dyd++;
			}
		}
	}
	if (dyd > 0)
	{
		vietos.push_back(dyd);
		dyd = -1;
	}
	sort(vietos.begin(), vietos.end(), [](int a, int b) {return make_pair(a % 2, -a) < make_pair(b % 2, -b);});
	for (int i : vietos)
	{
		if (i % 2 == 0)
		{
			a -= i / 2;
			b -= i / 2;
			ans += i;
		}
		else
		{
			if (a < b)
				swap(a, b);
			a -= i / 2 + 1;
			b -= i / 2;
			ans += i;
		}
	}
	if (a < 0)
		ans += a;
	if (b < 0)
		ans += b;
	cout << ans << "\n";


}