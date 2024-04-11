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

const int N = 1010;
int n;
const int l = 5;
char s[N][10];

void solve()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%s", s[i]);
	for (int i = 0; i < n; ++i)
		if ((s[i][0] == 'O' && s[i][1] == 'O') || (s[i][3] == 'O' && s[i][4] == 'O'))
		{
			puts("YES");
			if (s[i][0] == 'O' && s[i][1] == 'O')
				s[i][0] = '+', s[i][1] = '+';
			else
				s[i][3] = '+', s[i][4] = '+';
			for (int j = 0; j < n; ++j)
				printf("%s\n", s[j]);
			return;
		}
	puts("NO");
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("bandits.in", "r", stdin);
	//freopen("bandits.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
#endif
}