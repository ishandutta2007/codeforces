//#pragma comment(linker, "/STACK:mod00000000")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <ctime>
#include <memory.h>
#include <cstring>
#include <map>
#include <string>
#include <cassert>
#include <cmath>
#define sin sss
#define ll long long 

using namespace std;

const int maxn = (int)5e5 + 10;
int v[maxn];

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		int j = i;

		while (j != n - 1 && v[j] != v[j + 1]) {
			j++;
		}

		ans = max(ans, (j - i) / 2);

		int l = i + 1;
		int r = j - 1;
		int cnt = 1;

		while (l <= r) {
			v[l] ^= cnt & 1;
			if (l != r) {
				v[r] ^= cnt & 1;
			}

			l++;
			r--;
			cnt++;
		}

		i = j;
	}

	cout << ans << endl;

	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}

	return 0;
}