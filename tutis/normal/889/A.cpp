/*input
5
0 1 0 1 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	map<int, int>k;
	k[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		if (k.count(a))
		{
			int c = k[a];
			k.erase(a);
			k[i] = c;
		}
		else
		{
			k[i] = k.size();
		}
	}
	cout << k.size() << '\n';
}