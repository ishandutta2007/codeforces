/*input
3
AAA
BABA
AABBBABBBB
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int n = s.size();
		deque<char>x;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'B')
			{
				if (!x.empty())
				{
					x.pop_back();
				}
				else
					x.push_back('B');
			}
			else
				x.push_back(s[i]);
		}
		cout << x.size() << "\n";
	}
}