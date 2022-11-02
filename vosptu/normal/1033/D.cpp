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

#define P 998244353

int n;
int ans = 1;
long long a[1100];
bool used[1100];
map <long long, long long> Map;

long long gcd(long long a, long long b) {
	if (!a)
		return b;
	return gcd(b % a, a);
}

long long mul(long long a, long long b) {
	if (a >= (3e18 + b - 1) / b)
		return 3e18;
	else
		return a * b;
}

void fac4(int i) {
	long long l = 1, r = 2e9;
	while (l < r - 1) {
		long long mid = (l + r) / 2;
		if (mul(mul(mul(mid, mid), mid), mid) <= a[i])
			l = mid;
		else
			r = mid;
	}
	if (mul(mul(mul(l, l), l), l) == a[i]) {
		Map[l] += 4;
		used[i] = true;
	}
}

void fac3(int i) {
	long long l = 1, r = 2e9;
	while (l < r - 1) {
		long long mid = (l + r) / 2;
		if (mul(mul(mid, mid), mid) <= a[i])
			l = mid;
		else
			r = mid;
	}
	if (mul(mul(l, l), l) == a[i]) {
		Map[l] += 3;
		used[i] = true;
	}
}

void fac2(int i) {
	long long l = 1, r = 2e9;
	while (l < r - 1) {
		long long mid = (l + r) / 2;
		if (mul(mid, mid) <= a[i])
			l = mid;
		else
			r = mid;
	}
	if (mul(l, l) == a[i]) {
		Map[l] += 2;
		used[i] = true;
	}
}

int main() {
	cin >> n;
	// scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		if (!used[i])
			fac4(i);
		if (!used[i])
			fac3(i);
		if (!used[i])
			fac2(i);
		if (!used[i]) {
			bool fi = false;
			for (int j = 1; j <= n && !fi; j++)
				if (a[i] != a[j] && gcd(a[i], a[j]) != 1) {
					fi = true;
					long long x = gcd(a[i], a[j]);
					Map[x] += 1;
					Map[a[i] / x] += 1;
				}
			if (!fi) {
				int base = 1;
				for (int j = i + 1; j <= n; j++)
					if (a[i] == a[j]) {
						used[j] = true;
						base ++;
					}
				ans = 1LL * ans * (base + 1) * (base + 1) % P;
			}
		}
	}

	for (auto it: Map) {
		ans = 1LL * ans * (it.second + 1) % P;
	}

	cout << ans << endl;
	fflush(stdout);

}