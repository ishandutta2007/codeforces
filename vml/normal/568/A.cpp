#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <memory.h>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <vector>

using namespace std;

const int maxn = (int)3e6;

bool pr[maxn];

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}

bool go(int x) {
	if (x == 0) {
		return true;
	}

	vector <int> a;

	while (x != 0) {
		a.push_back(x % 10);
		x /= 10;
	}

	for (int i = 0; 2 * i <= (int)a.size(); i++) {
		if (a[i] != a[(int)a.size() - i - 1]) {
			return false;
		}
	}

	return true;
}

pair <long long, long long> v[maxn];

int main() {
	for (int i = 2; i < maxn; i++) {
		pr[i] = true;
	}

	for (int i = 2; i < maxn; i++) {
		if (pr[i]) {
			for (int j = i; (long long)i * j < maxn; j++) {
				pr[i * j] = false;
			}
		}
	}

	long long cnt_a = 0;
	long long cnt_b = 0;

	for (int i = 1; i < maxn; i++) {
		if (pr[i]) {
			cnt_a++;
		}

		if (go(i)) {
			cnt_b++;
		}

		v[i] = make_pair(cnt_a, cnt_b);
	}

	pair <long long, long long> best = v[maxn - 1];

	for (int i = maxn - 2; i >= 0; i--) {
		if (v[i].first * best.second < v[i].second * best.first) {
			best = v[i];
		}

		v[i] = best;
	}

	long long p, q;

	cin >> p >> q;

	for (int i = 1; i < maxn; i++) {
		if (v[i].first * q > v[i].second * p) {
			cout << i - 1 << endl;
			return 0;
		}
	}

	return 0;
}