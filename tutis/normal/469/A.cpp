/*input
3
1 10
0 10
10 10
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
	set<int>A;
	for (int t = 0; t < 2; t++)
	{
		int m;
		cin >> m;
		while (m--)
		{
			int a;
			cin >> a;
			A.insert(a);
		}
	}
	if (A.size() == n)
		cout << "I become the guy.\n";
	else
		cout << "Oh, my keyboard!\n";
}