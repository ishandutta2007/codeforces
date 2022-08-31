#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

bool used[1000];
const int N = 111;
int n;
string a[N];
string s;

bool tryAdd()
{
	char c = s.back();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (int)a[i].size() - 1; j++)
			if (a[i][j] == c)
			{
				s.push_back(a[i][j + 1]);
				used[s.back()] = 1;
				return true;
			}
	return false;
}

bool tryNew()
{
	for (int i = 0; i < n; i++)
	{
		char c = a[i][0];
		if (used[c]) continue;
		bool ok = true;
		for (int j = 0; ok && j < n; j++)
			for (int k = 1; ok && k < (int)a[j].size(); k++)
				ok &= c != a[j][k];
		if (!ok) continue;
		used[c] = 1;
		s.push_back(c);
		return true;
	}
	return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	while(true)
	{
		if (!s.empty() && tryAdd())
			continue;
		if (tryNew())
			continue;
		break;
	}
	cout << s << endl;

	return 0;
}