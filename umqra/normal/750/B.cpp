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

const int R = 20 * 1000;
const int NORTH = 1;
const int SOUTH = -1;
const int ANY = 0;

void move(int &pos, int t, int dir, bool &correct)
{
	if (pos == 0)
	{
		if (dir == NORTH)
			correct = false;
		if (dir == ANY)
			correct = false;
	}
	else if (pos == R)
	{
		if (dir == SOUTH)
			correct = false;
		if (dir == ANY)
			correct = false;
	}
	if (dir == ANY)
		return;
	if (dir == NORTH)
		pos -= t;
	else if (dir == SOUTH)
		pos += t;
	if (pos > R || pos < 0)
		correct = false;
}

int main()
{
	int n;
	scanf("%d", &n);
	int position = 0;
	bool correct = true;
	for (int i = 0; i < n && correct; i++)
	{
		int t;
		string dir;
		cin >> t >> dir;
		if (dir == "South")
			move(position, t, SOUTH, correct);
		else if (dir == "North")
			move(position, t, NORTH, correct);
		else
			move(position, t, ANY, correct);
	}
	if (position != 0)
		correct = false;
	printf("%s\n", correct ? "YES" : "NO");
	return 0;
}