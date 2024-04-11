#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int NLet = 26;
const int MaxN = 200000;
const int MaxM = 200000;

int main()
{
	int n, m;
	static char s[MaxN + 1], t[MaxM + 1];
	static int fp[NLet];
	static bool f[NLet][NLet][MaxN + 1];

	cin >> n >> m;
	scanf("%s", s);
	scanf("%s", t);

	for (char c = 'a'; c <= 'z'; c++)
	{
		static int next[MaxN + 1];
		next[0] = -1;
		for (int i = 1; i < m; i++)
		{
			int j = next[i - 1];
			while (j >= 0 && (t[j + 1] == c) != (t[i] == c))
				j = next[j];
			if ((t[j + 1] == c) == (t[i] == c))
				j++;
			next[i] = j;
		}
		for (int d = 'a'; d <= 'z'; d++)
		{
			for (int i = 0, j = -1; i < n; i++)
			{
				while (j >= 0 && (s[i] == d) != (t[j + 1] == c))
					j = next[j];
				if ((s[i] == d) == (t[j + 1] == c))
					j++;
				if (j == m - 1)
				{
					f[c - 'a'][d - 'a'][i - m + 1] = true;
					j = next[j];
				}
			}
		}
	}

	for (char c = 'a'; c <= 'z'; c++)
		fp[c - 'a'] = -1;
	for (int i = m - 1; i >= 0; i--)
		fp[t[i] - 'a'] = i;

	vector<int> res;
	for (int i = 0; i < n - m + 1; i++)
	{
		bool ok = true;
		static int mate[NLet];
		for (char c = 'a'; c <= 'z'; c++)
			mate[c - 'a'] = -1;
		for (char c = 'a'; c <= 'z'; c++)
			if (fp[c - 'a'] != -1)
			{
				char d = s[i + fp[c - 'a']];
				if (mate[c - 'a'] != -1 && mate[c - 'a'] != d)
				{
					ok = false;
					break;
				}
				if (mate[d - 'a'] != -1 && mate[d - 'a'] != c)
				{
					ok = false;
					break;
				}
				mate[c - 'a'] = d;
				mate[d - 'a'] = c;
				if (!f[c - 'a'][d - 'a'][i])
				{
					ok = false;
					break;
				}
			}
		if (ok)
			res.push_back(i + 1);
	}

	cout << res.size() << endl;
	for (int i = 0; i < (int)res.size(); i++)
		printf("%d ", res[i]);
	printf("\n");

	return 0;
}