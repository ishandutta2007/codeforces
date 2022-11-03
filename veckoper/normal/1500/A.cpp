#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 5e6 + 10;
int n, a[N];
pii st[N];
vector<int> ps[N];
inline void Print(int a, int b, int c, int d) {
	puts("YES");
	printf("%d %d %d %d\n", a, b, c, d);
	exit(0);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		ps[a[i]].push_back(i);
	}
	vector<int> bg;
	for (int i = 1; i < N; ++i) if ((int)ps[i].size() >= 2) {
		bg.push_back(i);
	}
	if ((int)bg.size() >= 2) {
		Print(ps[bg[0]][0], ps[bg[1]][0], ps[bg[0]][1], ps[bg[1]][1]);
	}
	if ((int)bg.size() == 1) {
		int sp = bg[0];
		if (ps[sp].size() >= 4) {
			Print(ps[sp][0], ps[sp][1], ps[sp][2], ps[sp][3]);
		} else {
			int x = ps[sp][0], y = ps[sp][1];
			st[a[x] + a[y]] = pii(x, y);
			for (int i = 1; i < (int)ps[sp].size(); ++i) a[ps[sp][i]] = -1;
		}
	}
	for (int i = 1; i <= n; ++i) if (a[i] != -1) 
		for (int j = i + 1; j <= n; ++j) if (a[j] != -1) {
			if (!st[a[i] + a[j]].first) {
				st[a[i] + a[j]] = pii(i, j);
			} else {
				Print(st[a[i] + a[j]].first, st[a[i] + a[j]].second, i, j);
			}
		}
	puts("NO");
	return 0;
}