#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <cstring>
#include <ctime>
#include <map>
#include <bitset>
#define ld double
#define ll long long
#define mp make_pair
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)

using namespace std;

int v[200010];
int f[200010];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i]--;
	}

	for (int i = 0; i < n; i++) {
		f[v[i]] = i;
	}

	ll ans = 0;

	for (int i = 0; i < n - 1; i++) {
		ans += abs(f[i] - f[i + 1]);
	}

	cout << ans << endl;

	return 0;
}