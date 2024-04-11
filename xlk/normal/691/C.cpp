#include <bits/stdc++.h>
using namespace std;
string s, a, b;
int n, l, r, e;
int main()
{
	cin >> s;
	s = "0" + s + ".";
	n = s.find('.');
	s = s.substr(0, n) + s.substr(n + 1, s.size() - n - 2);
	l = 0;
	r = s.size();
	while (l < r && s[l] == '0')
	{
		l++;
	}
	while (l < r && s[r - 1] == '0')
	{
		r--;
	}
	if (l == r)
	{
		puts("0");
	}
	else
	{
		e = n - l - 1;
		if (l + 1 < r)
		{
			s = s.substr(l, 1) + "." + s.substr(l + 1, r - l - 1);
		}
		else
		{
			s = s[l];
		}
		if (e)
		{
			cout << s << "E" << e << endl;
		}
		else
		{
			cout << s << endl;
		}
	}
	return 0;
}