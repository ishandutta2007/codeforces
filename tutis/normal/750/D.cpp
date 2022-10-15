/*input
1
3
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
	int t[n];
	for (int i = 0; i < n; i++)
		cin >> t[i];
	t[0]--;
	map<pair<int, int>, set<pair<int, int>>>X;
	queue<pair<pair<int, int>, pair<int, int>>>Q;
	Q.push({{0, 0}, {0, 2}});
	int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
	int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
	while (!Q.empty())
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int i = Q.front().second.first;
		int k = Q.front().second.second;
		Q.pop();
		if (i >= n)
			continue;
		if (X[make_pair(x, y)].count(make_pair(i, k)))
			continue;
		X[make_pair(x, y)].insert(make_pair(i, k));
		for (int c = 0; c < t[i]; c++)
		{
			x += dx[k];
			y += dy[k];
			X[make_pair(x, y)].insert(make_pair(-10, -10));
		}
		Q.push({{x, y}, {i + 1, (k + 1) % 8}});
		Q.push({{x, y}, {i + 1, (k + 7) % 8}});
	}
	cout << X.size() << "\n";
}