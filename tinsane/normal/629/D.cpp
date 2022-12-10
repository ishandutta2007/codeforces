#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <cstring>
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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#ifdef LOCAL
#define eprint() debugOutput()
#else
#define eprint() ;
#endif

const int P = (int) 1e9 + 7;
const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const double pi = 2 * atan2(1, 0);
const ld PI = 2 * atan2l(1, 0);
const double eps = 1e-8;
const ld EPS = 1e-12;
void debugOutput();

const int N = 1e5 + 10;
int n;
double ans;
ll pies[N];

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int r, h;
		cin >> r >> h;
		pies[i] = (ll)r * r * h;
	}
	set< pair<ll, ll> > st;
	for (int i = 0; i < n; ++i)
	{
		auto it = st.upper_bound(make_pair(pies[i] - 1, LINF));
		ll nV;
		if (it == st.begin())
		{
			st.emplace(pies[i], pies[i]);
			nV = pies[i];
			it = st.find(make_pair(pies[i], pies[i]));
		}
		else
		{
			nV = prev(it)->second + pies[i];
			st.emplace(pies[i], nV);
			it = st.find(make_pair(pies[i], nV));
		}
		for (++it; it != st.end();)
			if (it->second < nV)
			{
				auto tmp = it++;
				st.erase(tmp);
			}
			else
				break;
	}
	for (auto pie : st)
		ans = max((ld)ans, PI * pie.second);
	cout << setprecision(9) << fixed << ans;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("teleports.in", "r", stdin);
	//freopen("teleports.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0);

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}

void debugOutput()
{}