#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

const int MaxN = 100;
const int MaxM = 10000;

// adjust variable
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}


int main()
{
	int n, m;
	static char a[MaxN][MaxM];

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			while (a[i][j] = getchar(), a[i][j] != '0' && a[i][j] != '1');

	vector<int> v[MaxN];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (a[i][j] == '1')
				v[i].push_back(j - m);
		for (int j = 0; j < m; j++)
			if (a[i][j] == '1')
				v[i].push_back(j);
		for (int j = 0; j < m; j++)
			if (a[i][j] == '1')
				v[i].push_back(j + m);
	}

	for (int i = 0; i < n; i++)
		if (v[i].empty())
		{
			cout << "-1" << endl;
			return 0;
		}

	int res = INT_MAX;

	vector<int>::iterator p[MaxN + 1];
	for (int i = 0; i < n; i++)
		p[i] = v[i].begin();

	for (int i = 0; i < m; i++)
	{
		int t = 0;
		for (int j = 0; j < n; j++)
		{
			while (*p[j] < i)
				p[j]++;
			t += min(*p[j] - i, i - *(p[j] - 1));
		}
		tension(res, t);
	}
	cout << res << endl;

	return 0;
}