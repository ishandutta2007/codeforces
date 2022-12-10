#pragma region Template
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
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-12;

#pragma endregion

int n;
int v;
string op;
priority_queue<int, vector<int>, greater<int> > q;
vector< pair<string, int> > ans;

void solve()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> op;
		if (op[0] == 'r')
		{
			if (q.empty())
			{
				ans.emplace_back("insert", 4);
				q.push(4);
			}
			q.pop();
			ans.emplace_back(op, 0);
			continue;
		}
		cin >> v;
		if (op[0] == 'i')
		{
			ans.emplace_back(op, v);
			q.push(v);
		}
		else
		{
			for (; !q.empty() && q.top() < v; q.pop())
				ans.emplace_back("removeMin", 0);
			if (q.empty() || q.top() != v)
			{
				ans.emplace_back("insert", v);
				q.push(v);
			}
			ans.emplace_back(op, v);
		}
	}
	cout << ans.size() << '\n';
	for (auto e : ans)
		if (e.first[0] == 'r')
			cout << e.first << '\n';
		else
			cout << e.first << ' ' << e.second << '\n';
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("chocolate.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
	return 0;
}