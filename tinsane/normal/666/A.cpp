#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#include <unordered_map>
#include <unordered_set>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const ld PI = acos(-1);
const ld eps = 1e-8;
const ld EPS = 1e-12;

const int N = 1e4 + 10;
set<string> ans;
string s;
int n;
bool dp[2][N];

void solve()
{
	cin >> s;
	s = s.substr(5, s.size() - 5);
	n = s.size();

	reverse(s.begin(), s.end());
	dp[0][1] = true;
	dp[1][2] = true;
	for (int i = 0; i < n; ++i)
	{
		if (dp[0][i])
		{
			string to_ans = s.substr(i - 1, 2);
			reverse(to_ans.begin(), to_ans.end());
			ans.insert(to_ans);
			if (s.size() > i + 2 && (s[i - 1] != s[i + 1] || s[i] != s[i + 2]))
				dp[0][i + 2] = true;
			if (s.size() > i + 3)
				dp[1][i + 3] = true;

		}
		if (dp[1][i])
		{
			string to_ans = s.substr(i - 2, 3);
			reverse(to_ans.begin(), to_ans.end());
			ans.insert(to_ans);
			if (s.size() > i + 2)
				dp[0][i + 2] = true;
			if (s.size() > i + 3 && (s[i - 2] != s[i + 1] || s[i - 1] != s[i + 2] || s[i] != s[i + 3]))
				dp[1][i + 3] = true;
		}
	}

	cout << ans.size() << '\n';
	for (auto suf : ans)
		cout << suf << '\n';
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("chocolate.in", "r", stdin);
	//freopen("chocolate.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}