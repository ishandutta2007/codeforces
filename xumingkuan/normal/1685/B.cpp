#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>
using namespace std;
const int MAXN = 202020;
int a, b, c, d;
char s[MAXN];
void solve() {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	if (n != a + b + 2 * c + 2 * d) {
		printf("NO\n");
		return;
	}
	int cnta = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'A')
			cnta++;
	}
	if (cnta != a + c + d) {
		printf("NO\n");
		return;
	}
	vector<int> abab, baba;
	int tot_ab = 0, tot_ba = 0, tot_any = 0;
	for (int i = 1; i <= n; i++) {
		if (i != n && s[i] != s[i + 1]) {
			int j = i;
			while (j != n && s[j] != s[j + 1])
				j++;
			int len = j - i + 1;
			if (len % 2 == 1)
				tot_any += len / 2;
			else {
				if (s[i] == 'A') {
					tot_ab += len / 2;
					abab.push_back(len / 2);
				} else {
					tot_ba += len / 2;
					baba.push_back(len / 2);
				}
			}
			i = j;
		}
	}
	int ab_need = c - tot_ab;
	int ba_need = d - tot_ba;
	if (max(ab_need, 0) + max(ba_need, 0) <= tot_any) {
		printf("YES\n");
		return;
	}
	if (tot_ab <= c && tot_ba <= d) {
		printf("NO\n");
		return;
	}
	//printf("tot_ab=%d tot_ba=%d tot_any=%d\n", tot_ab, tot_ba, tot_any);
	if (tot_ab <= c) {
		swap(c, d);
		swap(tot_ab, tot_ba);
		swap(abab, baba);
	}
	// tot_ab > c
	sort(abab.begin(), abab.end());
	tot_ba += tot_any;
	for (int i = (int)abab.size() - 1; i >= 0; i--) {
		int now = abab[i];
		if (tot_ab - now < c) {
			int tmp = tot_ab - c;
			tot_ba += tmp - 1;
			break;
		}
		tot_ba += now - 1;
		tot_ab -= now;
		if (tot_ab == c)
			break;
	}
	//printf("after: tot_ab=%d tot_ba=%d\n", tot_ab, tot_ba);
	if (tot_ba >= d)
		printf("YES\n");
	else
		printf("NO\n");
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		solve();
	}
	return 0;
}