/*input
3 5

*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	n = (1 << n);
	set<int>galima;
	for (int i = 1; i < n; i++)
		galima.insert(i);
	galima.erase(x);
	int p = 0;
	vector<int>a;
	while (!galima.empty())
	{
		int f = *galima.begin();
		galima.erase(f);
		galima.erase(f ^ x);
		a.push_back(f ^ p);
		p = f;
	}
	cout << a.size() << "\n";
	for (int i : a)
		cout << i << " ";
	cout << "\n";
}