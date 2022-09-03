#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

const int maxn = 1005;

int s[maxn][2];
int n;

int main()
{
	scanf("%d", &n);
	int minh = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &s[i][0], &s[i][1]);
		minh = max(minh, min(s[i][0], s[i][1]));
	}
	ll answer = 1e18;
	for (int h = minh; h <= 1000; h++)
	{
		ll cursum = 0;
		for (int i = 0; i < n; i++)
		{
			int curmin = 2000;
			if (s[i][0] <= h) curmin = min(curmin, s[i][1]);
			if (s[i][1] <= h) curmin = min(curmin, s[i][0]);
			cursum += curmin;
		}
		answer = min(answer, cursum * h);
	}
	cout << answer << endl;
	return 0;
}