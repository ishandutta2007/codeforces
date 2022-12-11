#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

using ll = long long;
using pii = pair<int, int>;

set<string> s;

string convert(string x)
{
	string res = "";
	for (char c : x)
	{
		if (c == 'u')
			res += "oo";
		else
			res.push_back(c);
	}
	string t = "";
	for (int i = 0; i < (int)res.length(); i++)
	{
		if (res[i] == 'k')
		{
			bool ok = true;
			for (int s = i; s < (int)res.length(); s++)
			{
				if (res[s] == 'k' || res[s] == 'h')
				{
					if (res[s] == 'h')
						ok = false;
				}
				else
					break;
			}
			if (ok)
				t.push_back(res[i]);
		}
		else
			t.push_back(res[i]);
	}
	return t;
}

void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		str = convert(str);
		s.insert(str);
	}
	cout << s.size() << endl;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif

	solve();

	eprintf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}