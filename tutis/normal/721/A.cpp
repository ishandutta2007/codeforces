/*input
3
BBW
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
	string s;
	cin >> s;
	vector<int>ans;
	for (int i = 0; i < n; i++)
	{
		int k = 0;
		while (i + 1 < n && s[i + 1] == s[i])
		{
			k++;
			i++;
		}
		if (s[i] == 'B')
			ans.push_back(k + 1);
	}
	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i << '\n';
}