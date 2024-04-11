#include <algorithm>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <cassert>
#include <queue>
#include <ctype.h>
using namespace std;

#define ran(i, a, b) for (auto i = (a); i < (b); i++)
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
#if defined(SHIROKO1_LOCAL) && !defined(NDEBUG)
#define DEBUG(...) cerr << __VA_ARGS__ << endl;
#else
#define DEBUG(...) ((void)0)
#endif

static char A[1024][1024];
static int speed[100];
static vector<ii> area[100];
static int pos[100];

static ii DIRS[4] = {
	{-1, 0},
	{ 1, 0},
	{ 0, -1},
	{ 0,  1},
};

#define x first
#define y second

int main()
{
	int n, m, p;
	cin >> n >> m >> p;
	ran (i, 0, p)
		cin >> speed[i];
	ran (i, 0, n) {
		cin >> A[i];
		ran (j, 0, m) {
			if (isdigit(A[i][j])) {
				int pi = A[i][j] - '1';
				area[pi].push_back({ i, j });
			}
		}
	}
	for (;;) {
		bool stable = true;
		ran (k, 0, p) {
			ran (iter, 0, speed[k]) {
				bool pstable = true;
				int end = area[k].size();
				while (pos[k] < end) {
					ii s = area[k][pos[k]++];
					for (ii d : DIRS) {
						ii t = { s.first + d.first, s.second + d.second };
						if (A[t.x][t.y] == '.') {
							area[k].push_back(t);
							A[t.x][t.y] = '1' + k;
							DEBUG(t.x << " " << t.y << " TAKEN BY " << k+1);
							stable = false;
							pstable = false;
						}
					}
				}
				if (pstable)
					break;
			}
		}
		if (stable)
			break;
	}
	ran (i, 0, p-1) {
		printf("%i ", (int)area[i].size());
	}
	printf("%i\n", (int)area[p-1].size());
	return 0;
}