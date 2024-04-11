/*input
9
1 2 3 5 6 7 8 9 10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	vector<int>div[100001];
	for (int i = 2; i < 100001; i++)
	{
		for (int j = i; j < 100001; j += i)
		{
			div[j].push_back(i);
		}
	}
	int n;
	cin >> n;
	int mxs[100001];
	fill_n(mxs, 100001, 0);
	int ans = 0;
	while (n--)
	{
		int a;
		cin >> a;
		int gal = 1;
		for (int x : div[a])
			gal = max(gal, 1 + mxs[x]);
		ans = max(ans, gal);
		for (int x : div[a])
			mxs[x] = max(mxs[x], gal);
	}
	cout << ans << "\n";
}