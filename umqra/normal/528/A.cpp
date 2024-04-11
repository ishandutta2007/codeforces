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

set <int> yCoord, xCoord;
multiset <int> dx, dy;

void makeHor(int coord)
{
	auto it = xCoord.lower_bound(coord);
	auto pit = it;
	pit--;
	int a = *pit;
	int b = *it;
	int curDx = b - a;
	auto del = dx.find(curDx);
	dx.erase(del);
	dx.insert(coord - a);
	dx.insert(b - coord);

	xCoord.insert(coord);
}

void makeVer(int coord)
{
	auto it = yCoord.lower_bound(coord);
	auto pit = it;
	pit--;
	int a = *pit;
	int b = *it;
	int curDy = b - a;
	auto del = dy.find(curDy);
	dy.erase(del);
	dy.insert(coord - a);
	dy.insert(b - coord);

	yCoord.insert(coord);
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int w, h;
	scanf("%d%d", &w, &h);
	int n;
	scanf("%d", &n);
	xCoord.insert(0);
	xCoord.insert(w);
	dx.insert(w);

	yCoord.insert(0);
	yCoord.insert(h);
	dy.insert(h);
	
	for (int i = 0; i < n; i++)
	{
		char type;
		int coord;
		scanf(" %c%d", &type, &coord);
		if (type == 'H')
			makeVer(coord);
		else
			makeHor(coord);
		int a = *prev(dx.end());
		int b = *prev(dy.end());
		printf("%I64d\n", (ll)a * (ll)b);
	}

	return 0;
}