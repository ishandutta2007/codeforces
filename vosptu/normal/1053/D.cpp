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

#define P 1000000007

int n, p[2100000], ma[2100000], cnt_ma[2100000];
int mark[2100000];
bool used[2100000], solid[2100000];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	sort(p + 1, p + n + 1);
	for (int i = n; i; i--) {
		if (i < n && p[i] == p[i + 1]) {
			mark[p[i] - 1]++;
		}else {
			bool uu = false;
			for (int j = p[i]; j <= 2000000; j += p[i])
				if (mark[j])
					uu = true;
			if (!uu) {
				mark[p[i]]++;
			}else {
				mark[p[i] - 1] ++;
			}
		}
	}
	int ans = 1;
	for (int i = 2; i <= 2000000; i++) {
		if (!used[i]) {
			for (int j = 2 * i; j <= 2000000; j += i)
				used[j] = true;
		}else {
			continue;
		}
		ma[i] = 0;
		for (int j = i; j <= 2000000; j += i)
			if (mark[j]) {
				int cnt = 0;
				int copy = j;
				while (copy % i == 0) {
					copy /= i;
					cnt ++;
				}
				if (cnt > ma[i]) {
					ma[i] = cnt;
					cnt_ma[i] = 1;
				}else if (cnt == ma[i]) {
					cnt_ma[i] ++;
				}
			}
		for (int j = i; j <= 2000000; j += i)
			if (mark[j]) {
				int cnt = 0;
				int copy = j;
				while (copy % i == 0) {
					copy /= i;
					cnt ++;
				}
				if (cnt == ma[i] && cnt_ma[i] == 1) {
					solid[j] = true;
				}
			}
		
		for (int j = 1; j <= ma[i]; j++) {
			ans = 1LL * ans * i % P;
		}
	}
	for (int i = 1; i <= 2000000; i++)
		if ((mark[i] > 0 && !solid[i]) || mark[i] > 1) {
			ans++;
			break;
		}
	printf("%d\n", ans % P);
}