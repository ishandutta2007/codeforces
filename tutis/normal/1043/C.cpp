/*input
aaaaa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	pair<string, vector<int>>mn[n + 1];
	pair<string, vector<int>>mx[n + 1];
	mn[0] = {s, {}};
	mx[0] = {s, {}};
	for (int i = 1; i <= n; i++)
	{
		mn[i] = mn[i - 1];
		mn[i].second.push_back(0);
		mx[i] = mx[i - 1];
		mx[i].second.push_back(0);
		for (pair<string, vector<int>>j : {mn[i - 1], mx[i - 1]})
		{
			j.second.push_back(1);
			reverse(j.first.begin(), j.first.begin() + i);
			mn[i] = min(mn[i], j);
			mx[i] = max(mx[i], j);
		}
	}
	for (int i : mn[n].second)
		cout << i << " ";
}