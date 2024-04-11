#pragma comment (linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

const int maxn = 21;

int v[1 << maxn];
int help[1 << maxn];
long long f[maxn];
long long pow_two[2 * maxn];
long long number[maxn];

void go(int left, int d) {
	if (d == 0) {
		return;
	}

	go(left, d - 1);
	go(left + (1 << (d - 1)), d - 1);

	int first = left, second = left + (1 << (d - 1));
	long long ans = 0;
	int it = left;

	while (true) {
		if (first == (left + (1 << (d - 1))) && second == (left + (1 << d))) {
			break;
		}
		if (first == (left + (1 << (d - 1)))) {
			help[it] = v[second];
			it++;
			second++;
		} else if (second == (left + (1 << d))) {
			help[it] = v[first];
			it++;
			first++;
		} else if (v[first] > v[second]) {
			ans += left + (1 << (d - 1)) - first;
			number[d] += left + (1 << (d - 1)) - first;
			help[it] = v[second];
			it++;
			second++;
		} else if (v[first] < v[second]) {
			number[d] += left + (1 << d) - second;
			help[it] = v[first];
			it++;
			first++;
		} else if (v[first] == v[second]) {
			int pos_first = first;
			int pos_second = second;
			while (pos_first < left + (1 << (d - 1)) && v[pos_first] == v[first]) {
				help[it] = v[first];
				it++;
				pos_first++;
			}
			while (pos_second < left + (1 << d) && v[pos_second] == v[second]) {
				help[it] = v[second];
				it++;
				pos_second++;
			}
			ans += (pos_second - second) * (left + (1 << (d - 1)) - pos_first);
			number[d] += (pos_second - second) * (left + (1 << (d - 1)) - pos_first);
			number[d] += (pos_first - first) * (left + (1 << d) - pos_second);
			first = pos_first;
			second = pos_second;
		}
	}

	f[d] += ans;

	for (int i = left; i < left + (1 << d); i++) {
		v[i] = help[i];
	}
}

int now[maxn];

char s[maxn];

void print(long long t) {
	int pos = 0;
	if (t == 0) {
		s[pos] = (char)(t + '0');
		pos++;
	}
	while (t != 0) {
		s[pos] = (char)(t % 10 + '0');
		pos++;
		t /= 10;
	}
	for (int i = pos - 1; i >= 0; i--) {
		_putchar_nolock(s[i]);
	}
	_putchar_nolock('\n');
}

void scan(int &t) {
	t = 0;
	char k;
	while (true) {
		k = _getchar_nolock();
		if (k == ' ' || k == '\n') {
			break;
		}
		t *= 10;
		t += k - '0';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	pow_two[0] = 1;

	for (int i = 1; i < 2 * maxn; i++) {
		pow_two[i] = pow_two[i - 1] * 2;
	}

	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < (1 << n); i++) {
		scan(v[i]);
		//v[i] = i + 1;
	}

	go(0, n);

	for (int i = 1; i <= n; i++) {
		//printf("%lld %lld\n", f[i], number[i]);
	}
	
	int m;

	scanf("%d\n", &m);

	for (int it = 0; it < m; it++) {
		int pos;
		scan(pos);
		//pos = n;
		now[pos] = (now[pos] + 1) & 1;
		long long numb = 0;
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			if (now[i] == 0) {
				numb += number[i];
				ans += f[i];
			} else {
				ans = numb - ans;
				ans += number[i] - f[i];
				numb += number[i];
			}
		}
		print(ans);
	}

	return 0;
}