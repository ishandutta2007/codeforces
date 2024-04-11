#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <list>
using namespace std;

#define L 531441
int w, n, m;
int state[L], p3[L], s[L], ext[L], low[L], f[L];
int x[12][2];

int main() {
	scanf("%d%d%d", &w, &n, &m);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		s[a]++;
	}

	p3[0] = 1;
	for (int i = 1; i <= w; i++)
		p3[i] = p3[i - 1] * 3;

	for (int i = 0; i < (1 << w); i++)
		for (int j = 0; j < w; j++)
			if (i & (1 << j))
				ext[i] += p3[j];

	for (int i = 0; i < (1 << w); i++)
		for (int j = 0; j < (1 << w); j++)
			f[2 * ext[j] + ext[i & (~j)]] += s[i];

	for (int i = 0; i < (1 << w); i++)
		for (int j = 0; j < w; j++)
			if (i & (1 << j))
				low[i] = j;

	while (m--) {
		char S[20];
		scanf("%s", S);
		for (int i = 0; i < w - i - 1; i++)
			swap(S[i], S[w - i - 1]);
		for (int i = 0; i < w; i++) {
			if (S[i] == 'A') {
				x[i][0] = 2 * p3[i];
				x[i][1] = 0 * p3[i];
			}else if (S[i] == 'O') {
				x[i][0] = 0 * p3[i];
				x[i][1] = L;
			}else if (S[i] == 'X') {
				x[i][0] = 0 * p3[i];
				x[i][1] = 1 * p3[i];
			}else if (S[i] == 'a') {
				x[i][0] = L;
				x[i][1] = 1 * p3[i];
			}else if (S[i] == 'o') {
				x[i][0] = 1 * p3[i];
				x[i][1] = 2 * p3[i];
			}else {
				x[i][0] = 1 * p3[i];
				x[i][1] = 0 * p3[i];
			}
		}
		int ans = 0;
		state[0] = 0;
		for (int i = 0; i < w; i++)
			state[0] += x[i][0];
		if (state[0] < L)
			ans += s[0] * f[state[0]];
		for (int i = 1; i < (1 << w); i++) {
			state[i] = state[i - (1 << low[i])] - x[low[i]][0] + x[low[i]][1];
			if (state[i] < L)
				ans += s[i] * f[state[i]];
		}
		printf("%d\n", ans);
	}
}