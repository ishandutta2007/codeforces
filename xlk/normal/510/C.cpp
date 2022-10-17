#include <bits/stdc++.h>
using namespace std;
int n;
string s[100];
vector<int> a[26];
int d[26];
queue<int> q;
void _()
{
	for (int i = 1; i < n; i++)
	{
		unsigned j = 0;
		while (j < s[i-1].size() && j < s[i].size() && s[i-1][j] == s[i][j])
		{
			j++;
		}
		if (j == s[i-1].size())
		{
			
		}
		else if (j == s[i].size())
		{
			cout << "Impossible" << endl;
			return;
		}
		else
		{
			a[s[i-1][j] - 'a'].push_back(s[i][j] - 'a');
			d[s[i][j] - 'a']++;
		}
	}
	string s;
	for (int i = 0; i < 26; i++)
	{
		if (d[i] == 0)
		{
			q.push(i);
		}
	}
	while (q.size() > 0)
	{
		int x = q.front();
		s += 'a' + x;
		q.pop();
		for (int i: a[x])
		{
			if (--d[i] == 0)
			{
				q.push(i);
			}
		}
	}
	if (s.size() < 26)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		cout << s << endl;	
	}
	return;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	_();
	return 0;
}