#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

int n;
string s;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int ans1 = 0, ans2 = 0;
	cin >> n >> s;
	int len = -1;
	bool ins = false;
	for (char c : s)
	{
		if (c == '(')
		{
			if (len != -1)
			{
				ans1 = max(ans1, len);
				len = -1;
			}
			ins = true;
		}
		else if (c == ')')
		{
			if (len != -1)
			{
				ans2++;
				len = -1;
			}
			ins = false;
		}
		else if (c == '_')
		{
			if (len != -1)
			{
				if (ins)
					ans2++;
				else
					ans1 = max(ans1, len);
				len = -1;
			}
		}
		else
		{
			if (len == -1)
				len = 0;
			len++;
		}
	}
	if (len != -1)
		ans1 = max(ans1, len);

	cout << ans1 << " " << ans2 << endl;

	return 0;
}