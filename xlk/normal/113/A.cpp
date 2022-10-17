#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
string b[] = {"lios", "liala", "etr", "etra", "initis", "inites"};
int get(string s)
{
	for (int i = 0; i < 6; i++)
	{
		if (s.size() >= b[i].size() && s.substr(s.size() - b[i].size()) == b[i])
		{
			return i;
		}
	}
	return -1;
}
bool ok()
{
	int last01 = -1;
	int first23 = a.size();
	int last23 = -1;
	int first45 = a.size(); 
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == -1)
		{
			return false;
		}
		if (a[i] % 2 != a[0] % 2)
		{
			return false;
		}
		if (a[i] / 2 == 0)
		{
			last01 = max(last01, i);
		}
		if (a[i] / 2 == 1)
		{
			first23 = min(first23, i);
			last23 = max(last23, i);
		}
		if (a[i] / 2 == 2)
		{
			first45 = min(first45, i);
		}
	}
	return a.size() == 1 || (first23 == last23 && last01 < first23 && last23 < first45);
}
int main()
{
	while (cin >> s)
	{
		a.push_back(get(s));
	}
	cout << (ok() ? "YES" : "NO") << endl;
	return 0;
}