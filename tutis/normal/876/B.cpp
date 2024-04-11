/*input
3 2 3
1 8 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, k, m;
	cin >> n >> k >> m;
	map<int, vector<int>>X;
	while (n--)
	{
		int a;
		cin >> a;
		X[a % m].push_back(a);
		if (X[a % m].size() == k)
		{
			cout << "Yes\n";
			for (int i : X[a % m])
				cout << i << " ";
			cout << "\n";
			return 0;
		}
	}
	cout << "No\n";



}