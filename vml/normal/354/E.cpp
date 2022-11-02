#pragma comment(linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

#define lld I64d

int ans[10][10][6];

int v[6];

void rec(int pos) {
	if (pos == 6) {
		int sum = 0;
		for (int i = 0; i < 6; i++) {
			sum += v[i];
		}
		int l = sum % 10, r = sum / 10;
		if (ans[l][r][0] == -1) {
			for (int i = 0; i < 6; i++) {
				ans[l][r][i] = v[i];
			}
		}
	} else {
		v[pos] = 0;
		rec(pos + 1);
		v[pos] = 4;
		rec(pos + 1);
		v[pos] = 7;
		rec(pos + 1);
	}
}

vector <long long> res(6);

bool go(long long p) {
	if (p == 0) {
		return true;
	}
	int ost = p % 10;
	p /= 10;
	for (int j = 0; (j < 10) && (j <= p); j++) {
		if (ans[ost][j][0] != -1) {
			if (go(p - j)) {
				for (int i = 0; i < 6; i++) {
					res[i] *= 10;
					res[i] += ans[ost][j][i];
				}
				return true;
			}
		}
	}
	return false;
}

int main() {
#ifdef ONLINE_JUDGE
    //freopen("towers.in", "r", stdin);
    //freopen("towers.out", "w", stdout);
#endif
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			ans[i][j][0] = -1;
		}
	}
	rec(0);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		long long p;
		scanf("%lld", &p);
		if (go(p)) {
			for (int i = 0; i < 6; i++) {
				printf("%lld ", res[i]);
			}
		} else {
			printf("-1");
		}
		printf("\n");
		for (int i = 0; i < 6; i++) {
			res[i] = 0;
		}
	}
}