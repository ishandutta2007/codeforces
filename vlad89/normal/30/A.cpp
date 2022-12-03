#define _CRT_SECURE_NO_DEPRECATE
#pragma comment (linker, "/STACK:256000000")
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
	int a, b, n;
	scanf ("%d%d%d", &a, &b, &n);
	FOR (x, -1000, 1001) {
		int y = a;
		bool ok = true;
		REP (i, n) {
			y *= x;
			if (abs (y) > 1000)
			{
				ok = false;
				break;
			}
		}
		if (ok && y == b) {
			printf ("%d\n", x);
			return 0;
		}
	}
	printf ("No solution\n");
	return 0;
}