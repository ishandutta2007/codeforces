/*input
4 4
3 4 1 0
0 1 7 9
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int x[n], y[m];
	for (int &i : x)
		cin >> i;
	for (int &i : y)
		cin >> i;
	for (int i : x)
	{
		if (find(y, y + m, i) != y + m)
			cout << i << " ";
	}
	cout << "\n";
}