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

#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef vector<int>::iterator vint_iter;

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-13;

#pragma endregion
const int N = 3e5 + 10;
int n, q;
vector<int> poses[N];
set<int> bad;

void solve()
{
	scanf("%d%d", &n, &q);
	int sz = 0;
	for (int i = 0; i < q; ++i)
	{
		int t, v;
		scanf("%d%d", &t, &v);
		--v;
		if (t == 1)
		{
			bad.insert(sz);
			poses[v].push_back(sz);
			++sz;
		}
		else if (t == 2)
		{
			for (auto p : poses[v])
				if (bad.count(p))
					bad.erase(p);
			poses[v].clear();
		}
		else
			for (; bad.size() && *bad.begin() <= v; bad.erase(bad.begin()));
		printf("%d\n", (int)bad.size());
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("editor.in", "r", stdin);
	//freopen("intersection.out", "w", stdout);
#endif

	//int t;
	//scanf("%d", &t);
	//while(t--)
	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
}