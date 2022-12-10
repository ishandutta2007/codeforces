#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <functional>
#include <unordered_set>
#pragma comment(linker, "/STACK:167772160")

using namespace std;

#ifdef LOCAL
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...) ;
#endif

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

const double PI = 3.1415926535897932384626433;
const int INF = 1e9 + 10;
const ll LINF = 2e18 + 10;
const double eps = 1e-9;

struct Block
{
	ll len;
	char c;
	void read()
	{
		char t;
		cin >> len >> t >> c;
	}
};

const int N = 2e5 + 10;
int n, m, new_n, new_m;
Block s[N], t[N];
int pref1[2 * N], pref2[2 * N], seq[2 * N];

void get_pref(int* s, int n, int* pref)
{
	for (int i = 1; i < n; ++i)
	{
		int j = pref[i - 1];
		for (; j > 0 && s[i] != s[j]; j = pref[j - 1]);
		if (s[i] == s[j]) 
			++j;
		pref[i] = j;
	}
}

void solve()
{
	cin >> n >> m;
	new_n = n, new_m = m;
	for (int i = 0; i < n; ++i)
		t[i].read();
	for (int i = 0; i < m; ++i)
		s[i].read();
	for (int i = 1, j = 0; i < n; ++i)
	{
		if (t[i].c != t[j].c)
			t[++j] = t[i];
		else
			t[j].len += t[i].len, --new_n;
	}
	n = new_n;
	for (int i = 1, j = 0; i < m; ++i)
	{
		if (s[i].c != s[j].c)
			s[++j] = s[i];
		else
			s[j].len += s[i].len, --new_m;
	}
	m = new_m;
	if (m == 1)
	{
		ll ans = 0;
		for (int i = 0; i < n; ++i)
			if (t[i].c == s[0].c)
				ans += max(0LL, t[i].len + 1 - s[0].len);
		cout << ans;
		return;
	}
	for (int i = 0; i < m; ++i)
		seq[i] = s[i].c;
	seq[m] = 0;
	for (int i = 0; i < n; ++i)
		seq[m + 1 + i] = t[i].c;
	get_pref(seq, n + m + 1, pref1);
	for (int i = 1; i < m - 1; ++i)
		seq[i - 1] = s[i].len;
	seq[m - 2] = -1;
	for (int i = 0; i < n; ++i)
		seq[m - 1 + i] = t[i].len;
	get_pref(seq, n + m - 1, pref2);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (pref1[m + 1 + i] == m && pref2[m - 2 + i] == m - 2 && t[i].len >= s[m - 1].len && t[i - m + 1].len >= s[0].len)
			++ans;
	cout << ans;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0);

	solve();

	eprintf("\nTime : %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

	return 0;
}