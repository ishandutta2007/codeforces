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

const int N = (int)1e5 + 100;
const long long mod = (long long)1e9 + 9;

pii cube[N];
int down[N];

set <int> freeCubes;
map <pii, int> existedCubes;

int getId(int x, int y)
{
	if (existedCubes.find(make_pair(x, y)) == existedCubes.end())
		return -1;
	return existedCubes[make_pair(x, y)];
}

void calcDown(int id)
{
	int x = cube[id].first;
	int y = cube[id].second;
	down[id] = 0;
	for (int d = -1; d <= 1; d++)
	{
		int nx = x + d;
		int ny = y - 1;
		if (getId(nx, ny) != -1)
			down[id]++;
	}
}

void tryAddCube(int index)
{
	int x = cube[index].first;
	int y = cube[index].second;
	for (int d = -1; d <= 1; d++)
	{
		int nx = x + d;
		int ny = y + 1;
		int id = getId(nx, ny);
		if (id != -1 && down[id] == 1)
			return;
	}
	freeCubes.insert(index);
}

void freeCube(int index)
{
	int x = cube[index].first;
	int y = cube[index].second;
	existedCubes[make_pair(x, y)] = -1;
	freeCubes.erase(index);
	for (int d = -1; d <= 1; d++)
	{
		int nx = x + d;
		int ny = y - 1;
		int id = getId(nx, ny);
		if (id != -1)
			tryAddCube(id);

		nx = x + d;
		ny = y + 1;
		id = getId(nx, ny);
		if (id != -1)
			calcDown(id);
	}
	for (int d = -2; d <= 2; d++)
	{
		int nx = x + d;
		int ny = y;
		int id = getId(nx, ny);
		if (id != -1)
		{
			freeCubes.erase(id);
			tryAddCube(id);
		}
	}
}

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
		scanf("%d%d", &cube[i].first, &cube[i].second);
		existedCubes[cube[i]] = i;
	}

	for (int i = 0; i < n; i++)
		calcDown(i);
	for (int i = 0; i < n; i++)
		tryAddCube(i);

	long long number = 0;
	for (int i = 0; i < n; i++)
	{
		int cur = 0;
		if (!(i & 1))
			cur = *prev(freeCubes.end());
		else
			cur = *freeCubes.begin();
		number = (number * n) % mod;
		number = (number + cur) % mod;

		freeCube(cur);
	}
	cout << number;

	return 0;
}