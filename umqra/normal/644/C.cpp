#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <string>
using namespace std;

const string HTTP = "http://";
const int HTTP_LEN = (int)HTTP.length();

int getSlashPos(string &s)
{
	int pos = (int)s.length();
	for (int i = (int)s.length() - 1; i >= HTTP_LEN; i--)
	{
		if (s[i] == '/')
			pos = i;
	}
	return pos;
}

const int CNT = 2;
const int mod[] = {(int)1e9 + 7, (int)1e9 + 9};
const int p = 123817;

int add(int a, int b, int m)
{
	a += b;
	if (a < 0)
		return a + m;
	if (a < m)
		return a;
	return a - m;
}

int mult(int a, int b, int m)
{
	return (1LL * a * b) % m;
}

struct PolyHash
{
	int a[CNT];
	PolyHash () 
	{
		memset(a, 0, sizeof(a));
	}
	PolyHash (int _x)
	{
		for (int i = 0; i < CNT; i++)
			a[i] = _x;
	}
	void operator *= (int x)
	{
		for (int i = 0; i < CNT; i++)
			a[i] = mult(a[i], x, mod[i]);
	}
	void operator *= (const PolyHash &x)
	{
		for (int i = 0; i < CNT; i++)
			a[i] = mult(a[i], x.a[i], mod[i]);
	}
	void operator += (const PolyHash &x)
	{
		for (int i = 0; i < CNT; i++)
			a[i] = add(a[i], x.a[i], mod[i]);
	}
	bool operator < (const PolyHash &x) const
	{
		for (int i = 0; i < CNT; i++)
		{
			if (a[i] != x.a[i])
				return a[i] < x.a[i];
		}
		return false;
	}
	bool operator == (const PolyHash &x) const
	{
		for (int i = 0; i < CNT; i++)
		{
			if (a[i] != x.a[i])
				return false;
		}
		return true;
	}
};

map <string, vector<string>> paths;
map <PolyHash, vector<string>> result;
vector <vector<string>> ans;

int main()
{
	cin.tie(0);
	int n;
	scanf("%d", &n);
	string addr;
	for (int i = 0; i < n; i++)
	{
		cin >> addr;
		int pos = getSlashPos(addr);
		string suffix = addr.substr(pos);
		string prefix = addr.substr(0, pos);
		paths[prefix].push_back(suffix);
	}
	for (auto &e : paths)
	{
		sort(e.second.begin(), e.second.end());
		e.second.resize(unique(e.second.begin(), e.second.end()) - e.second.begin());

		PolyHash cur = PolyHash(0);
		for (auto &s : e.second)
		{
			for (auto &c : s)
			{
				cur *= p;
				cur += PolyHash(c);
			}
			cur *= p;
			cur += PolyHash('|');
		}

		result[cur].push_back(e.first);
	}
	for (auto &e : result)
	{
		if (e.second.size() > 1)
			ans.push_back(e.second);
	}
	printf("%d\n", (int)ans.size());
	for (auto &e : ans)
	{
		for (auto &s : e)
			printf("%s ", s.c_str());
		puts("");
	}
	return 0;
}