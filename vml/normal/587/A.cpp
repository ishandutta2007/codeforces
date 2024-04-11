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
#include <cassert>
#include <cmath>
#define ll long long 

using namespace std;

const int maxn = (int)2e6 + 10;
int cnt[maxn];

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		cnt[x]++;
	}

	int ans = 0;

	for (int i = 0; i < maxn; i++) {
		ans += cnt[i] & 1;
		cnt[i + 1] += cnt[i] >> 1;
	}

	cout << ans << endl;

	return 0;
}