#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string str)
{
	return str == string(str.rbegin(), str.rend());
}

int main()
{
	string str;
	cin >> str;

	int ans = 0;

	for (int i = 0; i < str.size(); i++)
	{
		for (int j = i + 1; j <= str.size(); j++)
		{
			if (is_palindrome({&str[i], &str[j]}) == false)
				ans = max(ans, j - i);
		}
	}

	printf("%d\n", ans);
}