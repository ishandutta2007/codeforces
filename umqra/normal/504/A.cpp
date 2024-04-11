#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
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

const int N = (1 << 17);
int deg[N];
int s[N];

bool cmp(int a, int b)
{
	if (deg[a] != deg[b])
		return deg[a] < deg[b];
	return a < b;
}

set<int, bool(*)(int, int)> setV(cmp);
pii listE[N];
int indE = 0;
int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &deg[i], &s[i]);
		setV.insert(i);
	}
	while (!setV.empty())
	{
		int v = *setV.begin();
		setV.erase(v);
		if (deg[v] == 0)
			continue;
		int to = s[v];
		listE[indE++] = mp(v, to);
		s[to] ^= v;
		setV.erase(to);
		deg[to]--;
		setV.insert(to);
	}
	printf("%d\n", indE);
	for (int i = 0; i < indE; i++)
		printf("%d %d\n", listE[i].X, listE[i].Y);
	
	return 0;
}