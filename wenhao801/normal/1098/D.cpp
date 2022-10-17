#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

#define ll long long
multiset <int> now[33]; ll s[33];

int main () {
	int Q = read(), i, j;
	while (Q--) {
		char op[2]; scanf("%s", op); int x = read();
		for (i = 0; x >= (1 << i); i++);
		if (op[0] == '+') now[i].insert(x), s[i] += x;
		else now[i].erase(now[i].find(x)), s[i] -= x;
		ll tmp = 0, out = 0;
		for (i = 0; i <= 30; i++) {
			out += now[i].size();
			if (!now[i].empty() && 2ll * tmp < (*now[i].begin())) --out;
			tmp += s[i];
		}
		printf("%lld\n", out);
	}
	return 0;
}