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

const int N = 2e5 + 10;
int n, m, seq[N], ri[N], ord[N], last[N];

void solve()
{
	fill(last, last + N, -1);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	for (int i = 0; i < m; ++i)
	{
		cin >> ord[i] >> ri[i];
		last[ri[i]] = i;
	}
	last[0] = m;
	int end;
	multiset<int> nums;
	for (int i = n; i > 0; --i)
		if (last[i] != -1)
		{
			end = i;
			for (int j = 0; j < end; ++j)
				nums.insert(seq[j]);
			break;
		}
	for (int i = end - 1; i >= 0; --i)
		if (last[i] != -1 && last[i] > last[end])
		{
			if (ord[last[end]] == 1)
			{
				auto it = prev(nums.end());
				for (int j = end - 1; j >= i; --j)
				{
					auto it1 = it--;
					seq[j] = *it1;
					nums.erase(it1);
				}
			}
			else
			{
				auto it = nums.begin();
				for (int j = end - 1; j >= i; --j)
				{
					auto it1 = it++;
					seq[j] = *it1;
					nums.erase(it1);
				}
			}
			end = i;
		}
	for (int i = 0; i < n; ++i)
		cout << seq[i] << ' ';
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

	eprintf("\nTime : %.3lf\n", (double) clock() / CLOCKS_PER_SEC);

	return 0;
}