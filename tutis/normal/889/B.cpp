/*input
4
mail
ai
lru
cf
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool ok(string a)
{
	if (a.size() > 26)
		return false;
	for (int i = 0; i < a.size(); i++)
		for (int j = i + 1; j < a.size(); j++)
			if (a[i] == a[j])
				return false;
	return true;
}
int pa[26];
string TEV[26];
int root(int i)
{
	if (i == pa[i])
		return i;
	return pa[i] = root(pa[i]);
}
string merge(string a, string b)
{
	if (a.empty())
		return b;
	if (b.empty())
		return a;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j])
			{
				string ret = "";
				if (i > j)
				{
					for (int c = 0; c <= i; c++)
						ret.push_back(a[c]);
				}
				else
				{
					for (int c = 0; c <= j; c++)
						ret.push_back(b[c]);
				}
				for (int t = 1;; t++)
				{
					if (i + t < a.size())
						ret.push_back(a[i + t]);
					else if (j + t < b.size())
						ret.push_back(b[j + t]);
					else
					{
						break;
					}
				}
				int kiek[26];
				fill_n(kiek, 26, 0);
				for (char c : ret)
				{
					kiek[c - 'a']++;
					if (kiek[c - 'a'] == 2)
					{
						cout << "NO\n";
						exit(0);
					}
				}
				if (ret.find(a) == string::npos || ret.find(b) == string::npos)
				{
					cout << "NO\n";
					exit(0);
				}
				return ret;
			}
		}
	}
	cout << "NO\n";
	exit(0);
	return a;
}
int main()
{
	iota(pa, pa + 26, 0);
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	string a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (!ok(a[i]))
		{
			cout << "NO\n";
			return 0;
		}
		string MERGE = a[i];
		for (char x : a[i])
			MERGE = merge(MERGE, TEV[root(x - 'a')]);
		for (char x : a[i])
			pa[root(x - 'a')] = root(MERGE.back() - 'a');
		int c = root(MERGE.back() - 'a');
		TEV[c] = MERGE;
	}
	vector<string>ans;
	for (int i = 0; i < 26; i++)
	{
		if (i == root(i))
		{
			ans.push_back(TEV[i]);
		}
	}
	sort(ans.begin(), ans.end());
	for (string a : ans)
		cout << a;
}