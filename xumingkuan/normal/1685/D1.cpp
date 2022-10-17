#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>
using namespace std;
const int MAXN = 500;
int n;
int p[MAXN];
int visit[MAXN], vn = 0;
int circ[MAXN], cn, pos[MAXN];
void get_circle() {
	cn = 0;
	vn++;
	for (int i = 1; i <= n; i++) {
		pos[p[i]] = i;
		if (visit[i] == vn)
			continue;
		visit[i] = vn;
		cn++;
		circ[i] = cn;
		int tmp = p[i];
		while (visit[tmp] != vn) {
			visit[tmp] = vn;
			circ[tmp] = cn;
			tmp = p[tmp];
		}
	}
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	while (true) {
		get_circle();
		if (cn == 1)
			break;
		for (int i = 1; i < n; i++) {
			if (circ[i] != circ[i + 1]) {
				swap(p[pos[i]], p[pos[i + 1]]);
				break;
			}
		}
	}
	int now = 1;
	for (int i = 1; i <= n; i++) {
		printf("%d ", now);
		now = pos[now];
	}
	printf("\n");
}
int main() {
	memset(visit, 0, sizeof(visit));
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		solve();
	}
	return 0;
}