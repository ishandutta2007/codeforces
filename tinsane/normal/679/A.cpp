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

bool is_prime(int x)
{
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return false;
	return true;
}

string res;

void solve()
{
	int div = 1;
	for (int i = 2; i * i <= 100; ++i)
	{
		if (!is_prime(i))
			continue;
		cout << i << endl;
		cin >> res;
		if (res == "yes")
		{
			div = i;
			break;
		}
	}
	if (div == 1)
	{
		cout << "prime" << endl;
		return;
	}
	for (int i = div; div * i <= 100; ++i)
	{
		if (!is_prime(i))
			continue;
		cout << div * i << endl;
		cin >> res;
		if (res == "yes")
		{
			cout << "composite" << endl;
			return;
		}
	}
	cout << "prime" << endl;
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
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
	return 0;
}