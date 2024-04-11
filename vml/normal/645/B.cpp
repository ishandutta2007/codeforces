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
#include <numeric>
#include <memory.h>
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define ui unsigned int
#define ld double

using namespace std;

int main() {
	int n, k;

	cin >> n >> k;

	int l = 0;
	int r = n - 1;

	ll ans = 0;

	while (l < r && k > 0) {
		k--;

		ans += 2 * (r - l) - 1;
		l++;
		r--;
	}

	cout << ans << endl;
	return 0;
}