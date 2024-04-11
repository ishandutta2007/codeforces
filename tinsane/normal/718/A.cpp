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
const double PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-13;

#pragma endregion

const int N = 2e5 + 10;
int n, t, pts;
char s[N];

void round(int pos)
{
	s[pos] = 0;
	n = pos;
	if (pos == pts + 1)
	{
		++s[pts - 1];
		n = pts;
		s[pts] = 0;
	}
	else
		++s[pos - 1];
	for (int i = pos - 1; i > pts; --i)
		if (s[i] <= '9')
			return;
		else
		{
			if (i != pts + 1)
			{
				++s[i - 1];
				s[i] = 0;
				n = i;
			}
			else
			{
				++s[pts - 1];
				s[pts] = 0;
				n = pts;
			}
		}
	for (int i = pts - 1; i >= 0; --i)
	{
		if (s[i] <= '9')
			return;
		if (i == 0)
		{
			s[i] = '1';
			s[n++] = '0';
			s[n] = 0;
		}
		else
		{
			s[i] = '0';
			++s[i - 1];
		}
	}
}

void kek()
{
	for (int i = pts + 1; i < n; ++i)
		if (s[i] >= '5')
		{
			round(i);
			--t;
			for (int j = i - 1; j > pts && t > 0; --j)
				if (s[j] >= '5')
				{
					--t;
					round(j);
				}
		}
}

void solve()
{
	scanf("%d%d", &n, &t);
	scanf("%s", s);
	for (int i = 0; i < n; ++i)
		if (s[i] == '.')
		{
			pts = i;
			break;
		}
	kek();
	puts(s);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("alter.in", "r", stdin);
	//freopen("alter.out", "w", stdout);
#endif

#ifdef STRESS
	while (true)
#endif
#ifdef MULTITEST
		int t;
	scanf("%d", &t);
	while (t--)
#endif
		solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
#endif
}