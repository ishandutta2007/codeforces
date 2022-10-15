/*input
codeforces
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	set<char>vowel = {'a', 'e', 'i', 'o', 'u'};
	set<char>consonant;
	for (char x = 'a'; x <= 'z'; x++)
	{
		if (x != 'n')
			consonant.insert(x);
	}
	for (char x : vowel)
		consonant.erase(x);
	string s;
	cin >> s;
	for (int i = 0; i + 1 < s.size(); i++)
	{
		if (consonant.count(s[i]) > 0)
		{
			if (vowel.count(s[i + 1]) == 0)
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	if (consonant.count(s.back()))
	{
		cout << "NO\n";
	}
	else
		cout << "YES\n";
}