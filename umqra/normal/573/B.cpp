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

const int N = (int)1e6 + 10;
int h[N];
int dist[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &h[i]);

	int minDist = 1;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		minDist = min(minDist, h[i]);
		dist[i] = minDist;
		minDist++;
	}
	minDist = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		minDist = min(minDist, h[i]);
		ans = max(ans, min(dist[i], minDist));
		minDist++;
	}
	cout << ans;
	return 0;
}