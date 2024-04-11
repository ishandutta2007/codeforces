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
#include <memory.h>

#define ll long long
#define ld double
#define forn(i, n) for (int i = 0; i < (int)n; i++)

using namespace std;

int v[100][100];
int ans[100];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (v[j][k] == i) {
					if (i == n - 1) {
						ans[j] = i;
						ans[k] = i + 1;
					} else if (ans[j] == 0 || ans[k] == 0) {
						if (ans[j] == 0) {
							ans[j] = i;
						} else {
							ans[k] = i;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}