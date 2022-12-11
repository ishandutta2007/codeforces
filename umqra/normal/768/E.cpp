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

map <pair<int, set<int>>, int> grandi_cache;

int get_grandi(int x, set<int> moves)
{
	if (x == 0)
		return 0;
	if (grandi_cache.count(make_pair(x, moves)) > 0)
		return grandi_cache[make_pair(x, moves)];
	vector <int> mex = vector<int>(x + 1);
	fill(mex.begin(), mex.end(), 0);
	for (int i = 1; i <= x; i++)
	{
		if (moves.count(i) > 0)
			continue;
		moves.insert(i);
		int cur = get_grandi(x - i, moves);
		moves.erase(i);
		mex[cur] = 1;
	}
	for (int i = 0; i <= x; i++)
		if (!mex[i])
			return grandi_cache[make_pair(x, moves)] = i;
	assert(1 == 0);
}
const int grandi[] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};
int main()
{
/*
	printf("const int grandi[] = {");
	for (int i = 0; i <= 60; i++)
		printf("%d, ", get_grandi(i, {}));
	printf("};\n");
*/
	int n;
	scanf("%d", &n);
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		res ^= grandi[x];
	}
	printf("%s\n", res == 0 ? "YES" : "NO");
	return 0;
}