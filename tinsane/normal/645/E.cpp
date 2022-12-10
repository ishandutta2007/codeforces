#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
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

const int P = 1e9 + 7;
const int N = 1e6 + 10;
const int ALP = 'z' - 'a' + 1;
int n, m, k, cnt, alp[ALP], inds[ALP];
string s;

int sum(int a, int b)
{
	a += b;
	if (a >= P)
		return a - P;
	return a;
}

int mul(int a, int b)
{
	return (ll) a * b % P;
}

int sub(int a, int b)
{
	return sum(a, P - b);
}

void apply(char c)
{
	cnt = sum(cnt, alp[c]);
	for (int i = 0; i < k; ++i)
	{
		if (i != c)
			alp[i] = sum(alp[i], alp[c]);
		if (inds[i] > inds[c])
			--inds[i];
	}
	inds[c] = k - 1;
}

void solve()
{
	cin >> n >> k >> s;
	m = s.size();
	for (auto& c : s)
		c -= 'a';
	fill(alp, alp + k, 1);
	cnt = 1;
	for (int i = 0; i < k; ++i)
		inds[i] = i;
	for (auto c : s)
		apply(c);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < k; ++j)
			if (inds[j] == 0)
			{
				apply(j);
				break;
			}
	cout << cnt;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("sequence.in", "r", stdin);
	//freopen("sequence.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0);

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}