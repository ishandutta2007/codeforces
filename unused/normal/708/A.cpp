#include "bits/stdc++.h"
using namespace std;

int main()
{
	string str;
	cin >> str;
	int idx;
	for (idx = 0; idx < str.size(); idx++)
		if (str[idx] != 'a') break;

	if (idx == str.size())
	{
		str.back() = 'z';
		cout << str << '\n';
		return 0;
	}

	while (idx < str.size() && str[idx] > 'a')
	{
		--str[idx];
		++idx;
	}

	cout << str << '\n';
}