#include <bits/stdc++.h>
using namespace std;

set<string> st, st2;

int main()
{
	cin.sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		st.emplace(move(str));
	}
	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;
		st2.emplace(move(str));
	}

	int common = 0;
	for (auto &&s : st)
	{
		if (st2.count(s))
		{
			common++;
			st2.erase(s);
		}
	}

	if (common % 2)
	{
		if (st.size() - common >= st2.size()) printf("YES");
		else printf("NO");
	}
	else
	{
		if (st.size() - common > st2.size()) printf("YES");
		else printf("NO");
	}
}