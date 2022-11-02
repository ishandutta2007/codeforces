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
	int n, b;

	scanf("%d %d", &n, &b);

	queue <ll> q;
	ll t = 0;
	ll sum = 0;

	for (int i = 0; i < n; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		while (!q.empty() && t <= x) {
			t += q.front();
			q.pop();
		}

		if (q.empty()) {
			if (t <= x) {
				t = x + y;
				sum = x + y;
				printf("%I64d ", t);
			} else {
				q.push(y);
				sum += y;
				printf("%I64d ", sum);
			}
		} else if ((int)q.size() == b) {
			printf("-1 ");
		} else {
			sum += y;
			q.push(y);
			printf("%I64d ", sum);
		}
	}

	return 0;
}