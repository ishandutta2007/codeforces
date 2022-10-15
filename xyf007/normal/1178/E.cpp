#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
string s, ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	int l = 0, r = (int)s.size() - 1;
	while (r - l >= 3)
	{
		if (s[l] == s[r])
		{
			ans.push_back(s[l]);
			l++;
			r--;
		}
		else
		{
			if (s[l] == s[r - 1])
			{
				ans.push_back(s[l]);
				l++;
				r -= 2;
			}
			else
			{
				if (s[l + 1] == s[r])
				{	
					ans.push_back(s[l + 1]);
					l += 2;
					r--;
				}
				else
				{
					ans.push_back(s[l + 1]);
					l += 2;
					r -= 2;
				}
			}
		}
	}
	cout << ans;
	if (l <= r)
	{
		cout << s[l];
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}