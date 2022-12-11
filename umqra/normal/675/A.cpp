#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

void answer(bool ok)
{
	if (ok)
		puts("YES");
	else
		puts("NO");
}

int main()
{
	ll a, b, c;
	cin >> a >> b >> c;
	if (c == 0)
		answer(a == b);
	else if (c < 0)
	{
		answer(b <= a && (b - a) % c == 0);
	}
	else
	{
		answer(b >= a && (b - a) % c == 0);
	}
	return 0;
}