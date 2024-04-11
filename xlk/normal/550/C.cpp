#include <bits/stdc++.h>
using namespace std;
void gao(string s)
{
	s = "00" + s;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{
			for (int k = j + 1; k < s.size(); k++)
			{
				int t = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
				if(t % 8 == 0)
				{
					cout << "YES" << endl;
					cout << t << endl;
					return;
				}
			}
		}
	}
	cout << "NO" << endl;
	return;
}
int main()
{
	string s;
	cin >> s;
	gao(s);
	return 0;
}