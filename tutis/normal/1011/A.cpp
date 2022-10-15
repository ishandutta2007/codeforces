/*input
5 3
xyabd
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
bool galim[26];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	int n, k;
	cin >> n >> k;
	while (n--)
	{
		char x;
		cin >> x;
		galim[x - 'a'] = true;
	}
	vector<int>ans;
	for (int i = 0; i < 26; i++)
	{
		if (!galim[i])
			continue;
		if (ans.empty() || i > ans.back())
			ans.push_back(i + 1);
	}
	while (ans.size() > k)
		ans.pop_back();
	if (ans.size() < k)
	{
		cout << "-1\n";
		return 0;
	}
	cout << accumulate(ans.begin(), ans.end(), 0);
}