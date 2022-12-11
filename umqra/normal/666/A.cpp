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

string str;
const int N = (int)1e5 + 10;
const int LEN = 4;
const int mod = (int)1e9 + 7;

int add(int a, int b)
{
	a += b;
	if (a < 0)
		return a + mod;
	if (a < mod)
		return a;
	return a - mod;
}

int mult(int a, int b)
{
	return (1LL * a * b) % mod;
}

int dp[N][LEN];
int dpRev[N][LEN];

set <string> ans;
int main()
{
	cin >> str;
	for (int i = 2; i <= 3; i++)
		dpRev[(int)str.length() - i][i] = 1;
	for (int i = (int)str.length() - 1; i >= 0; i--)
	{
		for (int l = 2; l <= 3; l++)
		{
			if (!dpRev[i][l])
				continue;
			for (int nl = 2; nl <= 3; nl++)
			{
				int npos = i - nl;
				if (npos < 0)
					continue;
				if (str.substr(npos, nl) == str.substr(i, l))
					continue;
				dpRev[npos][nl] = 1;
			}
		}
	}

	for (int i = 5; i < (int)str.length(); i++)
		for (int l = 2; l <= 3; l++)
		{
			if (dpRev[i][l])
				ans.insert(str.substr(i, l));
		}
	printf("%d\n", (int)ans.size());
	for (string s : ans)
		printf("%s\n", s.c_str());

	return 0;
}