/*input
6
10 2 3 5 4 2

*/
#pragma GCC target ("avx2")
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
	vector<int>a(n);
	for (int &i : a)
		cin >> i;
	int ans = 0;
	while (!a.empty())
	{
		ans++;
		int x = *min_element(a.begin(), a.end());
		vector<int>b;
		for (int i : a)
			if (i % x != 0)
				b.push_back(i);
		a = b;
	}
	cout << ans << "\n";
}