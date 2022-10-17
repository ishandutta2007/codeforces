#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define vi vector<int>

vi solve1 (int r) {
	if (!r) { vi ret; return ret; }
	int hb = 1; while (hb <= r) hb <<= 1; hb >>= 1;
	int LB = hb - (r - hb + 1);
	vi ret = solve1(LB - 1);
	for (int i = LB; i <= r; i++) ret.push_back(r - (i - LB));
	return ret;
}

inline bool ispow2 (int n) { return !(n & (n - 1)); }
vi solve2 (int n) {
	if (n & 1) {
		if (n < 7) { vi ret; return ret; }
		vi ret = {3, 6, 1, 5, 4, 7, 2};
		for (int i = 8; i <= n; i += 2) ret.push_back(i + 1), ret.push_back(i);
		return ret;
	}
	else {
		vi ret = {3, 6, 1, 5, 4, 2};
		if (ispow2(n)) { ret.clear(); return ret; }
		for (int i = 7; i <= n; i += 2) {
			if (ispow2(i + 1)) ret.push_back(i + 2), ret.push_back(i + 3), ret.push_back(i), ret.push_back(i + 1), i += 2;
			else ret.push_back(i + 1), ret.push_back(i);
		}
		return ret;
	}
}

int main () {
	int n; scanf("%d", &n);

	if (n & 1) puts("NO");
	else {
		puts("YES"); vi ans = solve1(n);
		for (auto i: ans) printf("%d ", i);
		puts("");
	}

	vi ans = solve2(n);
	if (ans.empty()) puts("NO");
	else { puts("YES"); for (auto i: ans) printf("%d ", i); puts(""); }
	return 0;
}