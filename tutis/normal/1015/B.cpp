/*input
6
abcdef
abdfec
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
	string s, t;
	cin >> s >> t;
	vector<int>ans;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (s[j] == t[i])
			{
				for (int k = j - 1; k >= i; k--)
				{
					ans.push_back(k + 1);
					swap(s[k], s[k + 1]);
				}
				break;
			}
		}
	}
	if (s == t)
	{
		cout << ans.size() << "\n";
		for (int a : ans)
			cout << a << " ";
	}
	else
		cout << "-1\n";
}