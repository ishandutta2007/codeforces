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

bool check(long long l, long long r, long long m, long long t) {
	if (r <= m) {
		return m - l <= t;
	} else if (l >= m) {
		return r - m <= t;
	} else {
		return min(2 * (m - l) + (r - m), (m - l) + 2 * (r - m)) <= t;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector <long long> it(n);
	vector <long long> disk(m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &it[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%lld", &disk[i]);
	}
	long long left = 0;
	long long right = 2 * 10000000000;
	while (left != right) {
		long long mid = (left + right) / 2;
		int iter = 0;
		for (int i = 0; i < n; i++) {
			int niter = iter;
			while (niter < m && check(disk[iter], disk[niter], it[i], mid)) {
				niter++;
			}
			iter = niter;
		}
		if (iter == m) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	printf("%lld", left);
	return 0;
}