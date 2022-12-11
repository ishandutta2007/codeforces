#include <bits/stdc++.h>
using namespace std;

string str;

int main()
{
	int n; cin >> n >> str;
	string ans;
	for (int i = 0; i < str.size(); i++)
	{
		if ((str.size() - i) & 1) ans.push_back(str[i]);
		else ans.insert(ans.begin(), str[i]);
	}
	cout << ans;
}