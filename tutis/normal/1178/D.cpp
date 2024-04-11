/*input
8

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool prime(int ans)
{
	for (int i = 2; i * i <= ans; i++)
		if (ans % i == 0)
			return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int>>ans;
	for (int i = 0; i < n; i++)
		ans.push_back({i, (i + 1) % n});
	int a = 0;
	while (!prime(ans.size()))
	{
		ans.push_back({a % n, (a + 2) % n});
		if (a % 4 == 0)
		{
			a++;
		}
		else
			a += 3;
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i.first + 1 << " " << i.second + 1 << "\n";
}