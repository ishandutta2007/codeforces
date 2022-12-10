#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

typedef long long ll;
const int N = 105;

char buf[N];
string scan_token()
{
	scanf("%s", buf);
	return string(buf);
}

int n, m;
string names[N];
bool to_del[N];

void fail()
{
	puts("No");
	exit(0);
}

bool matches(string s, string pat)
{
	if ((int)s.length() != (int)pat.length())
		return false;
	for (int i = 0; i < (int)s.length(); i++)
	{
		if (pat[i] == '?')
			continue;
		if (pat[i] != s[i])
			return false;
	}
	return true;
}

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		names[i] = scan_token();
	int any_id = -1;
	for (int i = 0; i < m; i++)
	{
		int t;
		scanf("%d", &t);
		t--;
		any_id = t;
		to_del[t] = true;
	}

	int len = (int)names[any_id].length();
	bool eq = true;
	for (int i = 0; i < n; i++)
		if (to_del[i])
			eq &= (int)names[i].length() == len;
	if (!eq)
		fail();

	string res(len, '?');
	for (int p = 0; p < len; p++)
	{
		char c = -1;
		for (int i = 0; i < n && c != -2; i++)
			if (to_del[i])
			{
				if (c == -1)
					c = names[i][p];
				else if (c != names[i][p])
					c = -2;
			}
		if (c != -2)
			res[p] = c;
	}

	for (int i = 0; i < n; i++)
		if (!to_del[i] && matches(names[i], res))
			fail();

	puts("Yes");
	puts(res.c_str());
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif

	solve();

	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

	return 0;
}