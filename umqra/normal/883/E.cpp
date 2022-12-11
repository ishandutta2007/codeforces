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

map<char, vector<int>> get_letter_map(const string &s)
{
	auto m = map<char, vector<int>>();
	for (int i = 0; i < (int)s.length(); i++)
	{
		if (s[i] != '*')
			m[s[i]].push_back(i);
	}
	return m;
}

const int A = 1000;
int letters[A];

void solve()
{
	int n;
	scanf("%d", &n);
	string str;
	cin >> str;
	int cnt = 0;
	for (char c : str)
		letters[c] = -1;

	auto letter_map = get_letter_map(str);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		string cur;
		cin >> cur;
		auto cur_map = get_letter_map(cur);
		bool ok = true;
		for (auto &e : letter_map)
		{
			if (cur_map[e.first] != e.second)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			set <char> unique_char = set<char>(cur.begin(), cur.end());
			for (char c : unique_char)
				letters[c]++;
			cnt++;
		}
	}
	int ans = 0;
	for (char c = 'a'; c <= 'z'; c++)
	{
		if (letters[c] == cnt)
			ans++;
	}
	cout << ans << endl;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif

	cin.tie(0);
	solve();

	eprintf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}