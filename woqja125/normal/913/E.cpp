#include<vector>
#include<cstdio>
#include<queue>
#include<string>
using namespace std;
struct A {
	string s;
	bool operator<(const A &t) const {
		if (s.length() != t.s.length()) return s.length() > t.s.length();
		return s > t.s;
	}
};
A ans[256][3];
vector<int> v;
int full = (1 << 8) - 1;
int getb() {
	int x;
	int re = 0;
	scanf("%d", &x);
	for (int i = 0; i < 10; i++) {
		re += (x % 10)<<i;
		x /= 10;
	}
	return re;
}
inline void add(priority_queue<pair<A, int>> &H, int x, int t) {
	H.emplace(ans[x][t], x * 4 + t);
}
int main() {
	int n;
	for (int i = 0; i < 256; i++)for (int j = 0; j < 3; j++) ans[i][j].s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

	priority_queue<pair<A, int>> H;

	ans[15][0].s = "x";
	H.emplace(ans[15][0], 15 * 4);
	ans[51][0].s = "y";
	H.emplace(ans[51][0], 51 * 4);
	ans[85][0].s = "z";
	H.emplace(ans[85][0], 85 * 4);

	int maxc = 0;

	while (!H.empty()) {
		int x = H.top().second;
		int t = x % 4;
		x = x / 4;
		if (H.top().first < ans[x][t]) {
			H.pop();
			continue;
		}
		H.pop();
		A &s = ans[x][t];
		// to large t
		for (int tt = t + 1; tt < 3; tt++) {
			if (ans[x][tt] < s) {
				ans[x][tt] = s;
				add(H, x, tt);
			}
		}

		// add ()
		A newS = { "(" + s.s + ")" };
		if (ans[x][0] < newS) {
			ans[x][0] = newS;
			add(H, x, 0);
		}

		// add not
		if (t == 0) {
			int nx = full ^ x;
			A newS = { "!" + ans[x][t].s };
			if (ans[nx][0] < newS) {
				ans[nx][0] = newS;
				add(H, nx, 0);
			}
		}

		for (auto u:v) {
			int ux = u / 4;
			int ut = u % 4;
			string us = ans[ux][ut].s;
			// u & x
			if (t <= 1 && ut <= 1) {
				A newS = max<A>({us+"&"+s.s}, {s.s+"&"+us});
				if (ans[ux & x][1] < newS) {
					ans[ux & x][1] = newS;
					add(H, ux&x, 1);
				}
			}

			// u | x
			A newS = max<A>({ us + "|" + s.s }, { s.s + "|" + us });
			if (ans[ux | x][2] < newS) {
				ans[ux | x][2] = newS;
				add(H, ux|x, 2);
			}
		}

		v.emplace_back(x * 4 + t);
	}

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		printf("%s\n", ans[getb()][2].s.c_str());
	}

	return 0;
}