/*input
2 3
a
b
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<pair<int, char>>kaimyn[101010];
int timer = 1;
void pridek(int i, string &a, int j)
{
	if (j == a.size())
		return;
	for (auto x : kaimyn[i])
	{
		if (x.second == a[j])
			return pridek(x.first, a, j + 1);
	}
	kaimyn[i].push_back({timer++, a[j]});
	return pridek(kaimyn[i].back().first, a, j + 1);
}
int dfs(int i)
{
	if (kaimyn[i].empty())
		return 1;
	for (auto j : kaimyn[i])
		if (dfs(j.first) == 0)
			return 1;
	return 0;
}
int dfs1(int i)
{
	if (kaimyn[i].empty())
		return 0;
	for (auto j : kaimyn[i])
		if (dfs1(j.first) == 0)
			return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	while (n--)
	{
		string a;
		cin >> a;
		pridek(0, a, 0);
	}
	if (dfs(0) && dfs1(0))
	{
		cout << "First\n";
		return 0;
	}
	if (dfs1(0))
	{
		if (k % 2 == 1)
		{
			cout << "First\n";
			return 0;
		}
		else
		{
			cout << "Second\n";
			return 0;
		}
	}
	cout << "Second\n";
	return 0;

}