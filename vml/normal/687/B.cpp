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

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

const int maxn = (int)1e6 + 10;

ll nod(ll a, ll b) {
	if (b == 0) {
		return a;
	}

	return nod(b, a % b);
}

ll nok(ll a, ll b) {
	return a / nod(a, b) * b;
}

int main() {
	int n;
	ll k;
	ll c = 1;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		ll x;

		scanf("%I64d", &x);

		c = nok(c, x);

		c = nod(c, k);
	}

	if (c != k) {
		printf("No");
	} else {
		printf("Yes");
	}

	return 0;
}