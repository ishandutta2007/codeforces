/*input
hellno
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool consonant(char x)
{
	for (char y : { 'a', 'e', 'i', 'o', 'u'})
		if (x == y)
			return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	if (s.size() == 1)
	{
		cout << s << "\n";
		return 0;
	}
	string pradzia;
	pradzia.push_back(s[0]);
	for (int i = 1; i + 1 < s.size(); i++)
	{
		pradzia.push_back(s[i]);
		if (consonant(s[i - 1]) && consonant(s[i]) && consonant(s[i + 1]))
		{
			if (s[i - 1] == s[i] && s[i] == s[i + 1])
				continue;
			if (pradzia.size() == 1)
				continue;
			cout << pradzia << " ";
			pradzia = "";
		}
	}
	pradzia.push_back(s.back());
	cout << pradzia << "\n";
}