#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <memory.h>
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define ui unsigned int
#define ld double

using namespace std;

int main() {
	vector <int> can;

	int n, m;

	cin >> n >> m;

	int ans = (int)1e9;

	for (int i = n; i <= 3 * n; i++) {
		int x = i / 3;

		x = min(x, i - n);

		ans = min(ans, max(2 * i, (i / 3) * 3 + (m - x) * 3));
	}

	cout << ans << endl;

	return 0;
}