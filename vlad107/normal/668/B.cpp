#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>
 
using namespace std;

const int N = 1e6 + 100;

int n, q, a[2][N], it[2], fr, nn;

void printArray() {
	for (int i = 0; i < n / 2; i++) {
		printf("%d ", a[fr][(it[fr] + i) % nn]);
		printf("%d ", a[fr^1][(it[fr^1] + i) % nn]);
	}
	puts("");
}

int main() {
//	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &q);
	int cur = 0;
	for (int i = 0; i < n; i += 2) a[0][cur++] = i + 1;
	cur = 0;
	for (int i = 1; i < n; i += 2) a[1][cur++] = i + 1;
	it[0] = it[1] = 0;
	fr = 0;
	nn = n / 2;
	while (q--) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int x;
			scanf("%d", &x);
			if (x < 0) x += n;
			x = n - x;
			int k = x / 2;
			it[0] = (it[0] + k) % nn;
			it[1] = (it[1] + k) % nn;
			if (x & 1) {
				++it[fr];
				if (it[fr] >= nn) it[fr] -= nn;
				fr ^= 1;
			}
		} else {
			fr ^= 1;
		}
//		printArray();
	}
	printArray();
}