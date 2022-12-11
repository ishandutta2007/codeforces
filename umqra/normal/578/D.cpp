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

const int N = (int)2e5 + 10;
char str[N];
int jump[N];
int pos[N];
int cntP = 0;

int getCountPos(int l, int r)
{
	return upper_bound(pos, pos + cntP, r) - lower_bound(pos, pos + cntP, l);
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	scanf(" %s", str);
	long long ans = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (i >= n - 2)
			jump[i] = i;
		if (str[i] == str[i + 2])
			jump[i] = jump[i + 2];
		else
			jump[i] = i + 2;
	}
	for (int i = n - 1; i > 0; i--)
	{
		if (str[i] != str[i - 1])
			pos[cntP++] = i;
	}
	sort(pos, pos + cntP);
	for (int i = 0; i < n; i++)
	{
		ans += m - 1;
		if (i == n - 1)
			break;
		ans += (ll)getCountPos(i + 1, n) * (m - 1);
		if (str[i] != str[i + 1])
		{
			ans += (ll)(m - 1) * (n - i - 1);
			int near = min(jump[i], jump[i + 1]);
			ans -= getCountPos(i + 1, near - 1);
		}
	}

	cout << ans << endl;
	return 0;
}