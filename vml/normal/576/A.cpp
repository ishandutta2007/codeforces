#pragma comment (linker, "/STACK:1000000000")
  
#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
  
using namespace std;

int cnt[1010];

int main() {
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x = i;
		for (int j = 2; j * j <= x; j++) {
			int f = 0;
			while (x % j == 0) {
				x /= j;
				f++;
			}

			cnt[j] = max(cnt[j], f);
		}

		if (x != 1) {
			cnt[x] = max(cnt[x], 1);
		}
	}

	int ans = 0;

	for (int i = 1; i <= 1000; i++) {
		int x = cnt[i];

		ans += x;
	}

	cout << ans << endl;

	for (int i = 1; i <= 1000; i++) {
		int f = i;
		for (int j = 0; j < cnt[i]; j++) {
			printf("%d ", f);
			f *= i;
		}
	}

	return 0;
}