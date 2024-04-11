/*input
3 4
aba
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string t = "";
	while (k > 0)
	{
		for (int i = 0; i <= t.size(); i++)
		{
			if (i + n - 1 >= t.size())
			{
				bool blogai = false;
				for (int j = i; j < t.size(); j++)
					if (t[j] != s[j - i])
						blogai = true;
				if (!blogai)
				{
					for (int j = i; j <= i + n - 1; j++)
						if (j >= t.size())
							t.push_back(s[j - i]);
					break;
				}
			}
		}
		k--;
	}
	cout << t << "\n";
}/**/