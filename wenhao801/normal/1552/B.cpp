#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <random>

using namespace std;
mt19937 RND(123456);

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

struct node { int val[5]; bool operator > (const node &tmp) const { int ret = 0; for (int i = 0; i < 5; i++) ret += val[i] < tmp.val[i]; return ret >= 3; } };
int n; vector <node> a, v, tmp;

int main () {
	int T = read();
	while (T--) {
		n = read(); int i, j;
		for (i = 1; i <= n; i++) { node now; for (j = 0; j < 5; j++) now.val[j] = read(); a.push_back(now), v.push_back(now); }
		while (v.size() > 1) {
			int id = RND() % v.size();
			tmp.clear();
			for (auto i: v) if (i > v[id]) tmp.push_back(i);
			tmp.push_back(v[id]);
			v.clear();
			while (!tmp.empty()) v.push_back(tmp.back()), tmp.pop_back();
		}
		node now = v[0]; v.pop_back();
		int ret = 0;
		for (auto i: a) ret += now > i;
		if (ret == n - 1) { for (i = 0; i < n; i++) if (!(now > a[i])) { cout << i + 1 << endl; break; } }
		else puts("-1");
		v.clear(); a.clear(); tmp.clear();
	}
	return 0;
}