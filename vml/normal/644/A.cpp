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
	int n, a, b;

	cin >> n >> a >> b;

	int x = n / 2;
	int y = n - x;
	swap(x, y);

	if (x > (a * b + 1) / 2 || y > (a * b) / 2) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			int tp = (i + j) % 2;

			if (tp == 0 && x != 0) {
				printf("%d ", x * 2 - 1);
				x--;
			} else if (tp == 1 && y != 0) {
				printf("%d ", 2 * y);
				y--;
			} else {
				printf("0 ");
			}
		}

		printf("\n");
	}

	return 0;
}