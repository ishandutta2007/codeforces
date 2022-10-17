#include <bits/stdc++.h>
using namespace std;
string s;
int z;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{
			for (int k = 0; i + k < s.size() && s[i + k] == s[j + k];)
			{
				z = max(z, ++k);
			}
		}
	}
	cout << z << endl;
	return 0;
}