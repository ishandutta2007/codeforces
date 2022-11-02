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

const int maxn = 3010;
int v[maxn];
int mas[maxn];
int t;

double eps = 10e-6;

double ans(int t) {
	if (t == 1) {
		return 1.0;
	}
	if (t == 0) {
		return 0.0;
	}
	return (4.0 + ans(t - 2));
}

int main() {
#ifdef ONLINE_JUDGE
    //freopen("circuit.in", "r", stdin);
    //freopen("circuit.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	while (true) {
		bool yes = false;
		for (int i = 0; i < n - 1; i++) {
			if (v[i] > v[i + 1]) {
				swap(v[i], v[i + 1]);
				t++;
				yes = true;
			}
		}
		if (!yes) {
			break;
		}
	}
	printf("%.6lf", ans(t));
	return 0;
}